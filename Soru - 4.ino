//  _ ___ _______     ___ ___ ___  ___ _   _ ___ _____ ___ 
// / |_  )__ /   \   / __|_ _| _ \/ __| | | |_ _|_   _/ __| 
// | |/ / |_ \ |) | | (__ | ||   / (__| |_| || |  | | \__ \ 
// |_/___|___/___/   \___|___|_|_\\___|\___/|___| |_| |___/ 
// 
// Soru - 4
// 
// Made by Omermendi Omermendi
// License: CC-BY-SA 3.0
// Downloaded from: https://circuits.io/circuits/4652174-soru-4

#include <Servo.h>

Servo serMot;

String komut;
int deg = 0;
// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(9600);
  Serial.println("Program BASLADI");
  DDRD  |= (1 << 7);
  PORTB |= (1 << 0) | (1 << 1) | (1 << 2) | (1 << 3);
  serMot.attach(2);
  serMot.write(0);
}
// the loop routine runs over and over again forever:
void loop() {
  while (Serial.available() > 0) {
    komut +=  Serial.readString();
  }
  if(komut == "BASLA"){
    PORTD |= (1 << 7);
    deg = PINB;
    Serial.println(deg);
    deg = map(deg,0,15,0,180);
  }else{
  	komut = "";
  }
  serMot.write(deg);
  delay(15);
}
