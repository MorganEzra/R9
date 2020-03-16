#include <Adafruit_NeoPixel.h>
#include<SoftwareSerial.h>
#include<Servo.h>
#define RX 10
#define TX 11
#define servoPin 13
const int led_pin=7;
const int led=5;
const int bande1=5;
const int bande2=5;
int Sensor=3;
const int aimant=8;
SoftwareSerial BlueT(RX,TX);
char Data;
int coupj1=0;
int coupj2=0;
int j=1;
Servo servo;
int tirs =0;   //La cest les variables pourle nombres de tirs le le nombres de buts du j1 et du j2.
int j1g =0;
int j2g=0;


Adafruit_NeoPixel strip=Adafruit_NeoPixel(bande1,led_pin,NEO_GRB+NEO_KHZ800);
Adafruit_NeoPixel stripp=Adafruit_NeoPixel(bande2,led,NEO_GRB+NEO_KHZ800);

void setup() {
  Serial.begin(9600);
  BlueT.begin(9600);
  pinMode(Sensor,INPUT);
  pinMode(8,OUTPUT);
  strip.begin();
  strip.show();
  stripp.begin();
  stripp.show();
  digitalWrite(8,LOW);
  servo.write(90);
  

}

void loop() {
  servo.write(20);
  bool val=digitalRead(Sensor);
  strip.setBrightness(100);
  strip.show();
  stripp.setBrightness(100);
  stripp.show();
  strip.setPixelColor(coupj1,0,0,255); // fais clignoter la led en bleu pour savoir à quel moment nbre de tir on est
  stripp.setPixelColor(coupj2,0,0,255);
  stripp.show();
  strip.show();
  delay(150);
  strip.setPixelColor(coupj1,0,0,0);
  stripp.setPixelColor(coupj2,0,0,0);
  stripp.show();
  strip.show();
  delay(150);
  
   if (BlueT.available()){
    
    Data=BlueT.read();
    
  }
  else Data = 0;
  
  if (Data=='1') {
    digitalWrite(8,HIGH); // tire de l'electroaimant
 
      
    
  delay(2000);
  
  val=digitalRead(Sensor);
  
  
  while (digitalRead(8)==HIGH) { 


  
  switch(val) {  //  val sert à identifié si il y a but ou non. On va switcher val pour arriver dans le bon cas.
   
    
    
    case LOW:  // Donc si val vaut HIGH c'est qu'il y a  eu  but.
  

      delay(50);
    
     
    
      switch (j) { // Une fois qu'on est dans le cas ou il n'y as pas but on regarde quel joueur a tiré je suppose que j sert à ça.
            
                  
      case 1:  //Donc si j vaut 1 cest le joueur 1 qui a raté son tir.
       
        strip.setPixelColor(j1g,0,255,0);  //But donc allume la led qui clignotais en vert
        strip.show();
        Serial.print("C'est le joueur : ");
        Serial.println(j);
        coupj1+=1; // on fais clignoter en bleu la led d'après
        j1g+=1;     //on ajoute +1 pour si il y un but au prochain tir allumer la led d'après
        j+=1;           // On passe j à 2 pour que le joueur 2 joue au prochaine tir.
        digitalWrite(3,LOW);
        delay(300);
        break;         //On sort du premier switch car on a finis la première phase de tire
      
      case 2:
        stripp.setPixelColor(j2g,0,255,0); //même principe pour le j2
        stripp.show();
       Serial.println(j);
        coupj2+=1;
        j2g+=1;
        j-=1;
        Serial.println(j);
        digitalWrite(8,LOW);
        break;   // On sort du cas 2
      delay(300);
      default:
        // Juste pour le debugg mais pas essentiel.
        break;
      }

    
   
    break;  // Donc la on sort du cas LOW on a changé la valeur de J donc on remonte dans le while on refait 
            // une simulation de tirs mais pour l'autre joueur cette fois.
  
    case HIGH:
    delay(50);
    
      
      switch (j) {    // Pareil on prend le joueur qui nous intéresse 
       case 1:
        strip.setPixelColor(coupj1,255,0,0);  //Pas But donc allume la led qui clignotais en rouge
        strip.show();
        coupj1+=1;//il a louper donc je fais clignoter la led d'après
        j1g+=1;
        j+=1;// on passe à l'autre joueur
        digitalWrite(8,LOW);
        delay(300);
        break;
      case 2:
          //Serial.println("Le joueur 2 a marqué wooooo");
          stripp.setPixelColor(coupj2,255,0,0);  //Pas But donc allume la led qui clignotais en rouge
          stripp.show();
          coupj2+=1;   // Si le j2 a louper on lui enlève un coup
          j2g+=1;
          j-=1;
          digitalWrite(8,LOW);
          delay(300);
          break;
      }
     
  break;  // Donc la pareil on sort du cas HIGH on a changé la valeur de J donc on remonte dans le while on refait 
            // une simulation de tirs mais pour l'autre joueur cette fois.
      
    }
   tirs++;  // a la fin du  switch(val) on incrément tirs pour dire que un tir a été réalise peu importe son résultat
            // si tu compte en fonction des tirs marqué increement une varaible dans les switch de HIGH.
  }
  }

    


   


  while (BlueT.available()) BlueT.read();
  
  if (Data=='2') {
    Serial.println("dbcjbdsjbsdc");
  
    servo.write(150);
 
  }
  
  if (Data=='4') {
     Serial.println("dcddxikx");
    servo.write(40);
    
  }
   //electroaimant enfoncer



 

 
  
 }
