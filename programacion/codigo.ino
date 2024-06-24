int IN1  = 10; //MOTOR ARRASTRE A 
int IN2  = 11;//MOTOR ARRASTRE B
int IN3  = 12; //MOTOR CRUSE A
int IN4  = 13; //MOTOR CRUSE B
int Velocidad1 = 60;  // traccion 
int Velocidad2 = 150;  //cruse

#include <Ultrasonic.h>
Ultrasonic ultrasonic1(31,37); //SENSOR IZQUIERDO
int distance1;                 //ALMASEN DE DATOS IZQUIERDO 

Ultrasonic ultrasonic2(40,43); //SENSOR DERECHO
int distance2;                 //ALMASEN DE DATOS DERECHA 

Ultrasonic ultrasonic3(53,50); //SENSOR FRONTAL 
int distance3;                 //ALMASEN DE DATOS FRONTAL 

void setup() {
  Serial.begin(115200);
 pinMode(IN1, OUTPUT);
 pinMode(IN2, OUTPUT);
 pinMode(IN3, OUTPUT);
 pinMode(IN4, OUTPUT);
 digitalWrite(IN1, LOW);
 digitalWrite(IN2, LOW);
 digitalWrite(IN3, LOW);
 digitalWrite(IN4, LOW);
}

void loop() {
   distance1 = ultrasonic1.read();
   distance2 = ultrasonic2.read();
   distance3 = ultrasonic3.read();
   
   Serial.print("didtancia1 CM  ");
   Serial.println(distance1);
   Serial.print("didtancia2 CM  ");
   Serial.println(distance2);
   Serial.print("didtancia3 CM ");
   Serial.println(distance3);
  
  if(distance1, distance2, distance3 <= 4){
   robotAvanza();
  }
  if(distance1, distance2, distance3 > 40){
   noCruza();
  }
  if(distance1 < 30){
   robotDerecha();
  }
  if(distance2 < 30){
   robotIzquierda(); 
  }
  if(distance3 < 40){
   robotDerecha(); 
  }

}

// void loop(){

// } 
void robotAvanza(){
  // digitalWrite(IN3,HIGH);
  analogWrite(IN3,Velocidad1);
  digitalWrite(IN4,LOW);
  Serial.println(Velocidad1);
}

void noCruza(){
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
}

void robotDerecha()
{ digitalWrite(IN1,LOW);
  analogWrite(IN2,Velocidad2);
  digitalWrite(IN2,HIGH);
}

void robotIzquierda()
{ digitalWrite(IN2,LOW);
  analogWrite(IN1,Velocidad2); 
  digitalWrite(IN1,HIGH);
}
