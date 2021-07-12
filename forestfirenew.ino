#include <Servo.h>
Servo myservo;
int flame = 10;
int gas = 9;
int red = 6;
int green = 7 ;
int buzzer = 13 ;
void setup ()
{
  pinMode (flame, INPUT) ;
  pinMode (gas, INPUT) ;
  pinMode (red, OUTPUT) ;
  pinMode (green, OUTPUT) ;
  pinMode (buzzer, OUTPUT) ;
  Serial.begin(9600);
  myservo.attach(8);
  myservo.write(0);
}

void loop ()
{
  int fval = digitalRead(flame) ;
  int gval = digitalRead(gas);
  

  if ( gval == HIGH or fval == HIGH)
  {
    
    
    Serial.println("1");
    digitalWrite(red, HIGH);
    digitalWrite(buzzer, HIGH);
    digitalWrite(green, LOW);
    myservo.write(180);
  }
  
  else
  {
    Serial.println("0");
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);
    digitalWrite(buzzer, LOW);
    myservo.write(0);
  }
  delay(100);
}
