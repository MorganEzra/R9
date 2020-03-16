#include<SoftwareSerial.h>
#include <Servo.h>
#define RX 10
#define TX 11
#define servoPin 13
Servo servo;
SoftwareSerial BlueT(RX,TX);

char Data;


void setup() {
  Serial.begin(9600);
  BlueT.begin(9600);
  servo.attach(servoPin);
 

}

void loop() {
  if (BlueT.available()){
    Data=BlueT.read();
    //Serial.print(Data);
  
    }
    if (Data=='1') {
      servo.write(-60);
      //delay(50);
       
    }
    if (Data=='2') {
      servo.write(20);
      //delay(50);
     
    }
    if (Data=='4') {
      servo.write(-20);
      //delay(50);
      
      }

    if (Data=='3') {}
    delay(50);
    
  
 

}
