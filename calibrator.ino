#include <Servo.h> 

Servo Horizontal;
Servo Vertical;
Servo One;
Servo Two;
 
int servoH = 90;   
int servoV = 90; 
int servo1 = 90;
int servo2 = 90;

void setup()
{
  Serial.begin(9600);
  Horizontal.attach(9); 
  Vertical.attach(10);
  One.attach(6);
  Two.attach(5);
  Serial.println("leftTop\trightTop\tleftDown\trightDown");
  Serial.println("---\t---\t---\t---\t");
}

void loop()
{

  // values indoors -30, +5, -10, -11
  
  int leftTop = analogRead(A0); 
  Serial.print(String(leftTop) + "\t");
  
  int rightTop = analogRead(A2) - 5; 
  Serial.print(String(rightTop) + "\t");
  
  int leftDown = analogRead(A1); 
  Serial.print(String(leftDown) + "\t");
  
  int rightDown = analogRead(A3) + 4; 
  Serial.print(String(rightDown) + "\n");



  Horizontal.write(77);
  Vertical.write(30);
  One.write(90);
  Two.write(70);

}
  
