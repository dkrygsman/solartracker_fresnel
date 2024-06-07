#include <Servo.h> 

Servo Horizontal;
Servo Vertical;
Servo Horizontal2;
Servo Vertical2;
 
int servoH = 90;  
int servoV = 90; 

void setup()
{
  Serial.begin(9600);
  Horizontal.attach(9); 
  Vertical.attach(10);
  Horizontal2.attach(6); 
  Vertical2.attach(5);
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
  
  int rightDown = analogRead(A3) - 4; 
  Serial.print(String(rightDown) + "\n");
  
  int delay_time = analogRead(4)/20; 
  int thresh = analogRead(5)/4;
  
  int avgTop = (leftTop + rightTop)/2; 
  int avgBottom = (leftDown + rightDown)/2;
  int avgLeft = (leftTop + leftDown) / 2; 
  int avgRight = (rightTop + rightDown) / 2; 

  int deltaVert = avgTop - avgBottom; 
  deltaVert = abs(deltaVert);
  
  int deltaHoriz = avgLeft - avgRight;
  deltaHoriz = abs(deltaHoriz);
  
  if (deltaVert > thresh)
  {
    if (avgTop > avgBottom)
    {
      servoV = servoV + 1;
      if (servoV > 180)
      {
        servoV = 180;
      }
    }
    else if (avgTop < avgBottom)
    {
      servoV= servoV - 1;
      if (servoV < 0)
      {
        servoV = 0;
      }
    }
    Vertical.write(servoV);
    Vertical2.write(servoV);
   }
  
   if (deltaHoriz > thresh) 
   {
    if (avgLeft > avgRight)
    {
      servoH = servoH + 1;
      if (servoH < 0)
      {
      servoH = 0;
      }
    }
    else if (avgLeft < avgRight)
    {
      servoH = servoH - 1;
      if (servoH > 180)
      {
        servoH = 180;
      }
    }
    
    Horizontal.write(servoH);
    Horizontal2.write(servoH);
  }

//  Serial.print(String(servoH) + "\t");
//  Serial.print(String(servoV) + "\t");
//  Serial.print(String(rightDown) + "\t");
//  Serial.print(String(rightDown) + "\n");
  
  delay(delay_time);
} 
