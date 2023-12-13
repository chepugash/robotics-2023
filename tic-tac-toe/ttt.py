import math
import cv2 as cv
import numpy as np


FILENAME = 'g.jpg'

X = 'x'
O = 'o'
BLANK = '-'

WHITE = (255, 255, 255)

cells_content = [[BLANK, BLANK, BLANK],
                [BLANK, BLANK, BLANK],
                [BLANK, BLANK, BLANK]]


def is_less(frst, scnd):
    return frst < scnd

def is_large(frst, scnd):
    return frst > scnd

def is_middle(c, min, max):
    return min < c < max

def main():
    image = cv.imread(cv.samples.findFile(FILENAME))
    dst = cv.Canny(image, 50, 200, None, 3)
    gray_image = cv.cvtColor(dst, cv.COLOR_GRAY2BGR)
    lines = cv.HoughLines(dst, 1, np.pi / 180, 150, None, 0, 0)

    d = 0.05 
    ht = 1.57
    vt = 0.0
    same_d = 20

    h_lines = []
    v_lines = []

    if lines is not None:
        for i in range(0, len(lines)):

            r = lines[i][0][0]
            t = lines[i][0][1]

            a = math.cos(t)
            b = math.sin(t)

            x0 = a * r
            y0 = b * r

            p1 = (int(x0 + 1000 * (-b)), int(y0 + 1000 * a))
            p2 = (int(x0 - 1000 * (-b)), int(y0 - 1000 * a))

            if abs(vt - t) < d:
                same_exists = False
                for line in v_lines:
                    if abs(r - line[0][0]) < same_d:
                        same_exists = True
                if not same_exists:
                    v_lines.append(lines[i])
                    cv.line(gray_image, p1, p2, WHITE, 3, cv.LINE_AA)

            elif abs(ht - t) < d:
                same_exists = False
                for line in h_lines:
                    if abs(r - line[0][0]) < same_d:
                        same_exists = True
                if not same_exists:
                    h_lines.append(lines[i])
                    cv.line(gray_image, p1, p2, WHITE, 3, cv.LINE_AA)

    h_half_dist = abs(h_lines[0][0][0] - h_lines[1][0][0]) / 2
    v_half_dist = abs(v_lines[0][0][0] - v_lines[1][0][0]) / 2

    min_h_line = min(float(h_lines[0][0][0]), float(h_lines[1][0][0]))
    min_v_line = min(float(v_lines[0][0][0]), float(v_lines[1][0][0]))

    max_h_line = max(float(h_lines[0][0][0]), float(h_lines[1][0][0]))
    max_v_line = max(float(v_lines[0][0][0]), float(v_lines[1][0][0]))

    cells_centers = [
        [
            [min_v_line - v_half_dist, max_h_line + h_half_dist],
            [min_v_line + v_half_dist, max_h_line + h_half_dist],
            [max_v_line + v_half_dist, max_h_line + h_half_dist]
        ],
        [
            [min_v_line - v_half_dist, min_h_line + h_half_dist],
            [min_v_line + v_half_dist, min_h_line + h_half_dist],
            [max_v_line + v_half_dist, min_h_line + h_half_dist]
        ],
        [
            [min_v_line - v_half_dist, min_h_line - h_half_dist],
            [min_v_line + v_half_dist, min_h_line - h_half_dist],
            [max_v_line + v_half_dist, min_h_line - h_half_dist]
        ]
    ]

    # O
    circle_img = cv.imread(FILENAME)
    circle_img = cv.cvtColor(circle_img, cv.COLOR_BGR2GRAY)
    circle_img = cv.medianBlur(circle_img, 5)

    rows = circle_img.shape[0]
    circles = cv.HoughCircles(circle_img, cv.HOUGH_GRADIENT, 1, rows / 8, param1=100, param2=30, minRadius=0, maxRadius=100)

    if circles is not None:
        circles = np.uint16(np.around(circles))
        for i in circles[0, :]:
            center = (i[0], i[1])

            cv.circle(gray_image, center, 1, WHITE, 3)
            radius = i[2]
            cv.circle(gray_image, center, radius, WHITE, 3)

            center_x = center[0]
            center_y = center[1]

            if is_less(center_x, min_v_line) and is_less(center_y, min_h_line):
                cells_content[0][0] = O
            elif is_middle(center_x, min_v_line, max_v_line) and is_less(center_y, min_h_line):
                cells_content[0][1] = O
            elif is_large(center_x, max_v_line) and is_less(center_y, min_h_line):
                cells_content[0][2] = O
            elif is_less(center_x, min_v_line) and is_middle(center_y, min_h_line, max_h_line):
                cells_content[1][0] = O
            elif is_middle(center_x, min_v_line, max_v_line) and is_middle(center_y, min_h_line, max_h_line):
                cells_content[1][1] = O
            elif is_large(center_x, max_v_line) and is_middle(center_y, min_h_line, max_h_line):
                cells_content[1][2] = O
            elif is_less(center_x, min_v_line) and is_large(center_y, max_h_line):
                cells_content[2][0] = O
            elif is_middle(center_x, min_v_line, max_v_line) and is_large(center_y, max_h_line):
                cells_content[2][1] = O
            elif is_large(center_x, max_v_line) and is_large(center_y, max_h_line):
                cells_content[2][2] = O

    # X
    cross_img = cv.imread(FILENAME)
    cross_img = cv.cvtColor(cross_img, cv.COLOR_BGR2GRAY)
    ret, thresh = cv.threshold(cross_img, 100, 255, cv.THRESH_BINARY)
    contours, hierarchy = cv.findContours(thresh, cv.RETR_TREE, cv.CHAIN_APPROX_NONE)

    for contour in contours:
        area = cv.contourArea(contour)
        if 1000 < area < 10000:
            M = cv.moments(contour)
            if M['m00'] != 0:
                center_x = int(M['m10'] / M['m00'])
                center_y = int(M['m01'] / M['m00'])

                if is_less(center_x, min_v_line) and is_less(center_y, min_h_line) and cells_content[0][0] != O:
                    cells_content[0][0] = X
                elif is_middle(center_x, min_v_line, max_v_line) and is_less(center_y, min_h_line) and cells_content[0][1] != O:
                    cells_content[0][1] = X
                elif is_large(center_x, max_v_line) and is_less(center_y, min_h_line) and cells_content[0][2] != O:
                    cells_content[0][2] = X
                elif is_less(center_x, min_v_line) and is_middle(center_y, min_h_line, max_h_line) and cells_content[1][0] != O:
                    cells_content[1][0] = X
                elif is_middle(center_x, min_v_line, max_v_line) and is_middle(center_y, min_h_line, max_h_line) and cells_content[1][1] != O:
                    cells_content[1][1] = X
                elif is_large(center_x, max_v_line) and is_middle(center_y, min_h_line, max_h_line) and cells_content[1][2] != O:
                    cells_content[1][2] = X
                elif is_less(center_x, min_v_line) and is_large(center_y, max_h_line) and cells_content[2][0] != O:
                    cells_content[2][0] = X
                elif is_middle(center_x, min_v_line, max_v_line) and is_large(center_y, max_h_line) and cells_content[2][1] != O:
                    cells_content[2][1] = X
                elif is_large(center_x, max_v_line) and is_large(center_y, max_h_line) and cells_content[2][2] != O:
                    cells_content[2][2] = X

                cv.circle(gray_image, (center_x, center_y), 10, WHITE, -1)

    cv.imshow("", gray_image)
    cv.waitKey()

    for i in range(0, 3):
        print(cells_content[i])

    return cells_centers


main()
