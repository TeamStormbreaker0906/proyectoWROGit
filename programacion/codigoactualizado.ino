int IN1  = 10; //MOTOR ARRASTRE A 
int IN2  = 11;//MOTOR ARRASTRE B
int IN3  = 12; //MOTOR CRUSE A
int IN4  = 13; //MOTOR CRUSE B
int Velocidad1 = 60;  // traccion 
int Velocidad2 = 110;  //cruse

#include <Ultrasonic.h>
Ultrasonic ultrasonic1(33,32); //SENSOR IZQUIERDO
int distancia1;                 //ALMASEN DE DATOS IZQUIERDO 

Ultrasonic ultrasonic2(46,43); //SENSOR DERECHO
int distancia2;                 //ALMASEN DE DATOS DERECHA 

Ultrasonic ultrasonic3(50,53); //SENSOR FRONTAL 
int distancia3;                 //ALMASEN DE DATOS FRONTAL 
 
void robotAvanza(){
  // digitalWrite(IN3,HIGH);
  analogWrite(IN3,Velocidad1);
  digitalWrite(IN4,LOW);
  Serial.println(Velocidad1);
 // delayMicroseconds(100);
}

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
 robotAvanza(); 
 
 

   distancia1 = ultrasonic1.read(); //censor izquierdo 
   distancia2 = ultrasonic2.read(); //censor derecho
   distancia3 = ultrasonic3.read(); //censor delantero
   
   Serial.print("didtancia1 CM  ");
   Serial.println(distancia1); //distancia izquierda 
   Serial.print("didtancia2 CM  ");
   Serial.println(distancia2); //distancia derecha
   Serial.print("didtancia3 CM  ");
   Serial.println(distancia3); //distancia delantera 
  
  if(distancia1 < 20, distancia2 < 20, distancia3 < 20){ //si el sensor asa la distansia establesida deja de crusar 
   noCruza();
  } 
  if(distancia3 < 40 && distancia1 < distancia2){  
   robotDerecha();
   delay(10);  
  }
  if(distancia3 < 40 && distancia2 < distancia1){ 
   robotIzquierda();
   delay(10);
  }
  if(distancia3 > 40 && distancia2 < distancia1){ 
   robotIzquierda(); 
   delay(2);
  }
  if(distancia3 > 40 && distancia1 < distancia2){ 
   robotDerecha(); 
   delay(2);
  }  
}

// void loop(){

// } 

void noCruza() {
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
