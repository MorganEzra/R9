#include<SoftwareSerial.h>
#include <Servo.h>
#define RX 10
#define TX 11
#define servoPin 8
const int aimant=3;
SoftwareSerial BlueT(RX,TX);
char Data;
Servo servo;

void setup() {
  Serial.begin(9600);
  BlueT.begin(9600);
  pinMode(3,OUTPUT);
  digitalWrite(3,LOW);
  servo.attach(servoPin);
}

void loop() {
  if (BlueT.available()){
   Data=BlueT.read();
  }
  if (Data=='1'){
    delay(50);
    digitalWrite(3,HIGH);   
  }

    

  if (Data=='0'){
    digitalWrite(3,LOW);
  
  }
  

}
