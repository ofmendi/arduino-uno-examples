//  _ ___ _______     ___ ___ ___  ___ _   _ ___ _____ ___ 
// / |_  )__ /   \   / __|_ _| _ \/ __| | | |_ _|_   _/ __| 
// | |/ / |_ \ |) | | (__ | ||   / (__| |_| || |  | | \__ \ 
// |_/___|___/___/   \___|___|_|_\\___|\___/|___| |_| |___/ 
// 
// Soru - 3
// 
// Made by Omermendi Omermendi
// License: CC-BY-SA 3.0
// Downloaded from: https://circuits.io/circuits/4733666-soru-3

// the setup routine runs once when you press reset:

#include <Servo.h>

Servo serMot;

volatile int say 	= -1;
volatile int durum 	= 0;
int lastTime = 0;
const int potPin = A0;
int potDeg = 0;
int motDeg = 0;

void setup() {
  // initialize the digital pin as an output.
  Serial.begin(9600);
  DDRB 	|= (1 << 4);
  DDRD	|= (1 << 5);
  PORTD |= (1 << 2);
  attachInterrupt(0,fonk,RISING);
  serMot.attach(5);
  Serial.println("Program BASLADI");
}

void fonk(){
  say++;
  if(say == 2){
  	durum = !durum;
    say = 0;
  }
  digitalWrite(12,durum);
}

// the loop routine runs over and over again forever:
void loop() {
  if(millis() - lastTime > 500){
    say = 0;
    lastTime = millis();   
  }
  if(durum){
    potDeg = analogRead(potPin);
    motDeg = map(potDeg,0,1023,0,179);
    Serial.println(motDeg);
  }else{
    motDeg = 0;  
  }
  serMot.write(motDeg);
  delay(15);
}
