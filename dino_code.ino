#include<Servo.h>
#define threshold1 625
#define threshold2 450
#define threshold3 570
#define threshold1b 500
#define unpress_angle 0
#define press_angle 35

Servo servo;

void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  servo.attach(8);
  servo.write(unpress_angle);
  delay(1000);
  servo.write(press_angle);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int f=analogRead(A0);
  int u=analogRead(A1);
  int abhi=analogRead(A2);
  Serial.print("A0:");
  Serial.println(f);
  Serial.println(u);
  Serial.println(abhi);
//  delay(1000);
  if(analogRead(A2)>=threshold2)
  {
    if(analogRead(A0)<threshold1||analogRead(A1)<threshold3)
    {
      servo.write(press_angle);
      delay(150);
      servo.write(unpress_angle);
      delay(100);
    }
   }
  else{
    if(analogRead(A0)>=threshold1b || analogRead(A1)>=threshold2){
      servo.write(press_angle);
      delay(200);
      servo.write(unpress_angle);
      delay(150);
    }
  }
}
