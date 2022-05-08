#include <Servo.h>

int position = 0;

int i = 0;

int j = 0;

Servo servo_9;

void setup()
{
  servo_9.attach(9, 500, 2500);

  pinMode(7, OUTPUT);
  pinMode(3, OUTPUT);
  Serial.begin(9600);

  pinMode(10, OUTPUT);
}

void loop()
{
  position = 0;
  for (position = 1; position <= 90; position += 1) {
    servo_9.write(position);
    digitalWrite(7, HIGH);
    digitalWrite(3, LOW);
    Serial.println("door opening");
    delay(30); // Wait for 30 millisecond(s)
  }
  //tone(10, 523, 2000); // play tone 60 (C5 = 523 Hz), indicating that the door is open
  delay(5000); // Wait for 5000 millisecond(s)
  noTone(10);
  for (position = 90; position >= 1; position -= 1) {
    servo_9.write(position);
    digitalWrite(7, LOW);
    digitalWrite(3, HIGH);
    Serial.println("door closing");
    delay(30); // Wait for 30 millisecond(s)
  }
}
