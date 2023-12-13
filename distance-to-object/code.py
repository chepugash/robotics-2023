import cv2
import numpy as np

# Функция для вычисления фокусного расстояния камеры
def get_focal_length(actual_width, pixel_width, distance):
    focal_length = (distance * pixel_width) / actual_width
    return focal_length

# Функция для определения расстояния до объекта в видеопотоке
def get_distance(focal_length, actual_width, pixel_width):
    distance = (focal_length * actual_width) / pixel_width
    return distance

image = cv2.imread("init.jpg")
focal_length = 0
# Объект для замера
actual_width = 15  # Фактическая ширина объекта в сантиметрах
object_color = (0,0,0)  # Цвет объекта в формате BGR
# расстояние до объекта
distance = 30  # Расстояние до объекта в сантиметрах

# пороговые значения для выделение контура объекта (черный)
lower_threshold = np.array([0, 0, 0])  # Нижние значения диапазона цвета в HSV
upper_threshold = np.array([180, 50, 50])  # Верхние значения диапазона цвета в HSV

hsv = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)
gray = cv2.inRange(hsv, lower_threshold, upper_threshold)
contours, _ = cv2.findContours(gray, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
# самый большой контур
if contours:
    largest_contour = max(contours, key=cv2.contourArea)
    x, y, w, h = cv2.boundingRect(largest_contour)
    cv2.rectangle(image, (x, y), (x + w, y + h), (0, 255, 0), 2)

    # вычисление фокусного расстояния камеры
    focal_length = get_focal_length(actual_width, w, distance)
    print(f"Приблизительное фокусное расстояние камеры: {focal_length} пикселей")


# объект камеры
cap = cv2.VideoCapture(0)

while True:
    # кадр из видеопотока
    ret, frame = cap.read()
    if not ret:
        break

    # Преобразование изображения в пространство цветов HSV
    hsv_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
    
    # Применение пороговых значений для выделения объектов заданного (черного) цвета
    mask = cv2.inRange(hsv_frame, lower_threshold, upper_threshold)
    
    # Нахождение контуров объектов
    contours, _ = cv2.findContours(mask.copy(), cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    if (contours):
        largest_contour = max(contours, key=cv2.contourArea)
        x, y, w, h = cv2.boundingRect(largest_contour)
        
        # Ограничивающий прямоугольник вокруг контура
        x, y, w, h = cv2.boundingRect(largest_contour)
        
        # ширина прямоугольника в пикселях
        pixel_width = w
        
        # Вычисление расстояния до объекта
        obj_distance = get_distance(focal_length, actual_width, pixel_width)
        obj_distance = round(obj_distance)
        
        # Отображение ограничивающего прямоугольника и расстояние до объекта на изображении
        cv2.rectangle(frame, (x, y), (x+w, y+h), (0, 255, 0), 2)
        cv2.putText(frame, f"Distance: {obj_distance} cm", (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 0.9, (255, 255, 255), 2)
        
        # Показ изображения с ограничивающими прямоугольниками и расстоянием до объекта
        cv2.imshow("Object Detection", frame)
        
        # Прерывание цикла при нажатии клавиши "q"
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break
    else:
        print("Контуры такого цвета не распознаны")

cap.release()
cv2.destroyAllWindows()
