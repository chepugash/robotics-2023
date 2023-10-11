# include <Servo.h>

const int SERVO1_PIN = 4;
const int SERVO2_PIN = 3;

Servo servo1;
Servo servo2;

int angle1;
int angle2;
int space;
String in;

void setup() {
  Serial.begin(9600);
  pinMode(SERVO1_PIN, OUTPUT);
  pinMode(SERVO2_PIN, OUTPUT);
  servo1.attach(SERVO1_PIN);
  servo2.attach(SERVO2_PIN);
}

void loop() {
  if (Serial.available() > 0) {
    in = Serial.readString();
    space = in.indexOf(' ');
    angle1 = in.substring(0, space).toInt();
    angle2 = in.substring(space).toInt();
    servo1.write(angle1);
    servo2.write(angle2);
  }

}
