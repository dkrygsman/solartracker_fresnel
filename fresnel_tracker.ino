#include <Servo.h> // include Servo library 

Servo Horizontal;
Servo Vertical;
Servo One;
Servo Two;
Servo Three;
 
int servoH = 90;   
int servoV = 90; 
int servo1 = 90;
int servo2 = 90;
int servo3 = 90;

void setup()
{
  Serial.begin(9600);
  Horizontal.attach(9); 
  Vertical.attach(10);
  One.attach(6);
  Two.attach(11);
  Three.attach(3);
//  Serial.println("leftTop\trightTop\tleftDown\trightDown");
//  Serial.println("---\t---\t---\t---\t");

  Horizontal.write(77);
}


void loop()
{
  
    int leftTop = analogRead(A0) - 30; 
    //Serial.print(String(leftTop) + "\t");
     
    int rightTop = analogRead(A2) + 5; 
    //Serial.print(String(rightTop) + "\t");
        
    int leftDown = analogRead(A1) - 10; 
    //Serial.print(String(leftDown) + "\t");
        
    int rightDown = analogRead(A3) - 11; 
    //Serial.print(String(rightDown) + "\t");
        
    int delay_time = analogRead(4)/20; 
    int thresh = analogRead(5)/4;
    
    int avgTop = (leftTop + rightTop)/2; 
    int avgBottom = (leftDown + rightDown)/2; 
    
    int deltaVert = avgTop - avgBottom; 
    deltaVert = abs(deltaVert);
    
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
     }

     //Serial.print(String(servoV) + "\t");

    //----------------------------- SERVO 1 Section --------------------------------------------------------------------------------------------
     float h;
     float l;
     float servo1;
     float servo1_new;
     float servoV_rad = servoV * PI/ 180;
     float h_div;

    if(l > 11)
    {
     h = sin(servoV_rad) * 50;
     l = cos(servoV_rad) * 50;

     h_div = (h/(l-11));
     servo1 = atan(h/(l-11));
     if(servo1 > 0)
     {
      servo1 = servo1 * 180 / PI;
      servo1_new = ((servo1 - 25.5) / 2) + 12.75;
      
      One.write(servo1_new);
     }
    }

    if(l < 11)
    {
     h = sin(servoV_rad) * 50;
     l = cos(servoV_rad) * 50;

     h_div = (h/(11-l));
     servo1 = atan(h/(11-l));
     if(servo1 > 0)
     {
       servo1 = servo1 * 180 / PI;
       servo1 = 180 - servo1;
       servo1_new = ((servo1 - 25.5) / 2) + 12.75;
       One.write(servo1_new);
     }
    }
//    One.write(servo1);

    //----------------------------- SERVO 2 Section --------------------------------------------------------------------------------------------

     float h2;
     float l2;
     float servo2;
     float servo2_new;
     float h_div2;

    if(l2 > 22)
    {
     h2 = sin(servoV_rad) * 50;
     l2 = cos(servoV_rad) * 50;

     h_div2 = (h2/(l2-22));
     servo2 = atan(h2/(l2-22));
     if(servo2 > 0)
     {
       servo2 = servo2 * 180 / PI;
       servo2_new = ((servo2 - 32.8) / 2) + 16.4;
       Two.write(servo2_new);
     }
    }

    if(l2 < 22)
    {
     h2 = sin(servoV_rad) * 50;
     l2 = cos(servoV_rad) * 50;

     h_div2 = (h2/(22-l2));
     servo2 = atan(h2/(22-l2));
     if( servo2 > 0) 
     {
       servo2 = servo2 * 180 / PI;
       servo2 = 180 - servo2;
       servo2_new = ((servo2 - 32.8) / 2) + 16.4;
       Two.write(servo2_new);
     }
    }
//    Two.write(servo2);
    
//----------------------------- SERVO 3 Section --------------------------------------------------------------------------------------------

     float h3;
     float l3;
     float servo3;
     float servo3_new;
     float h_div3;

    if(l3 > 33)
    {
     h3 = sin(servoV_rad) * 50;
     l3 = cos(servoV_rad) * 50;

     h_div3 = (h3/(l3-33));
     servo3 = atan(h3/(l3-33));
     if(servo3 > 0)
     {
       servo3 = servo3 * 180 / PI;
       servo3_new = ((servo3 - 45) / 2) + 22.5;
       Three.write(servo3_new);
     }
    }

    if(l3 < 33)
    {
     h3 = sin(servoV_rad) * 50;
     l3 = cos(servoV_rad) * 50;

     h_div3 = (h3/(33-l3));
     servo3 = atan(h2/(33-l3));
     if( servo3 > 0) 
     {
       servo3 = servo3 * 180 / PI;
       servo3 = 180 - servo3;
       servo3_new = ((servo3 - 45) / 2) + 22.5;
       Three.write(servo3_new);
     }
    }
//    Three.write(servo3);
    
    //-------------------------------------------------------------------------------------------------------------------------------------------

  
     Serial.print(String(servoV) + "\t\t");
     Serial.print(String(h) + "\t");
     Serial.print(String(l) + "\t");
     Serial.print(String(servo1) + "\t");
     Serial.print(String(servo1_new) + "\t\t");

     Serial.print(String(h2) + "\t");
     Serial.print(String(l2) + "\t");
     Serial.print(String(servo2) + "\t");
     Serial.print(String(servo2_new) + "\t\t");

     Serial.print(String(h3) + "\t");
     Serial.print(String(l3) + "\t");
     Serial.print(String(servo3) + "\t");
     Serial.print(String(servo3_new) + "\n");
      
    
    delay(delay_time);
}
