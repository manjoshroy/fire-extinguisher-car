#include <Servo.h>
#define flame 3
#define pump 4
#define fireAlarm 5
#define m11 A0
#define m12 A1
#define m21 A2
#define m22 A3
char c='\0';
Servo myServo;
void checkCommand();
void setup() 
{
  Serial.begin(9600);
  pinMode(flame,INPUT);
  pinMode(pump,OUTPUT);
  pinMode(fireAlarm,OUTPUT);
  pinMode(m11,OUTPUT);
  pinMode(m12,OUTPUT);
  pinMode(m21,OUTPUT);
  pinMode(m22,OUTPUT);
  digitalWrite(m11,LOW);
  digitalWrite(m12,LOW);
  digitalWrite(m21,LOW);
  digitalWrite(m22,LOW);
  myServo.attach(2);
  myServo.write(45);
}
void loop()
{
  for(int i=45;i<135;i++)
  {
    if(digitalRead(flame)==LOW)
    {
      digitalWrite(m11,LOW);
      digitalWrite(m12,LOW);
      digitalWrite(m21,LOW);
      digitalWrite(m22,LOW);
      digitalWrite(pump,HIGH);
      digitalWrite(fireAlarm,HIGH);
      while(digitalRead(flame)==LOW)
      {
        delay(10);
      }
      digitalWrite(pump,LOW);
      digitalWrite(fireAlarm,LOW);
    }
    checkCommand();
    myServo.write(i);
    delay(10);
  }
  for(int i=135;i>=45;i--)
  {
    if(digitalRead(flame)==LOW)
    {
      digitalWrite(m11,LOW);
      digitalWrite(m12,LOW);
      digitalWrite(m21,LOW);
      digitalWrite(m22,LOW);
      digitalWrite(pump,HIGH);
      digitalWrite(fireAlarm,HIGH);
      while(digitalRead(flame)==LOW)
      {
        delay(10);
      }
      digitalWrite(pump,LOW);
      digitalWrite(fireAlarm,LOW);
    }
    checkCommand();
    myServo.write(i);
    delay(10);
  }
}
void checkCommand()
{

  if(Serial.available()>0)
  {
    c=Serial.read();
    if(c=='F')
    {
      digitalWrite(m11,HIGH);
      digitalWrite(m12,LOW);
      digitalWrite(m21,HIGH);
      digitalWrite(m22,LOW);
    }
    else if(c=='B')
    {
      digitalWrite(m11,LOW);
      digitalWrite(m12,HIGH);
      digitalWrite(m21,LOW);
      digitalWrite(m22,HIGH);
    }
    else if(c=='L')
    {
      digitalWrite(m11,LOW);
      digitalWrite(m12,HIGH);
      digitalWrite(m21,HIGH);
      digitalWrite(m22,LOW);
    }
    else if(c=='R')
    {
      digitalWrite(m11,HIGH);
      digitalWrite(m12,LOW);
      digitalWrite(m21,LOW);
      digitalWrite(m22,HIGH);
    }
    else if(c=='S')
    {
      digitalWrite(m11,LOW);
      digitalWrite(m12,LOW);
      digitalWrite(m21,LOW);
      digitalWrite(m22,LOW);
    }
  }
}