#include<Servo.h>
#include<SoftwareSerial.h>
#define RX 10
#define TX 11
#define servoPin 13
SoftwareSerial BlueT(RX,TX);
Servo servo;
char Data;
void setup() {
  Serial.begin(9600);
  BlueT.begin(9600);
  servo.attach(servoPin);
  servo.write(90);
  }
void loop() {
 
    if (BlueT.available()){
    Data=BlueT.read();
  }
  if (Data=='L'){
    Serial.println(Data);
    
    servo.write(150);
    delay(200);
    servo.write(90);
    }
  if (Data=='R') {
    Serial.println(Data);
    servo.write(40);
    delay(200);
    servo.write(90);
  }
  if (Data=='C'){
   
  }
  
  

}
