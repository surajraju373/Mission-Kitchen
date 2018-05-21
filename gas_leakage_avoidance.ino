/*
www.geekstips.com
MQ4 Gas Sensor - Arduino tutorial
*/
#include<Servo.h>
int servoPin= D0;
Servo servo;
int servoAngle=0;
const int gasPin = A0; //GAS sensor output pin to Arduino analog A0 pin

void setup(){
  Serial.begin(9600); //Initialize serial port - 9600 bps
  servo.attach(servoPin);
  pinMode(D1,HIGH);
}

void loop(){
float  reading = analogRead(gasPin);
  
  if(reading>170 && reading<250)
  {
   digitalWrite(D1,HIGH);
   delay(500);
   digitalWrite(D1,LOW);
   delay(500);
  }
  
  
  else if(reading>250)
 {
    Serial.print(reading);
    Serial.print("\t");
    Serial.println("Gas leaking");
    servo.write(90);
    delay(1000);
    for(servoAngle=0;servoAngle<180;servoAngle=servoAngle+10)
    {
      servo.write(servoAngle);
      delay(50);
    }
    for(servoAngle=180;servoAngle>0;servoAngle=servoAngle-10)
    {
    servo.write(servoAngle);
    delay(50);
    }

 }
  
  delay(1000); // Print value every 1 sec.
  
}
