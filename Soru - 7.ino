//  _ ___ _______     ___ ___ ___  ___ _   _ ___ _____ ___ 
// / |_  )__ /   \   / __|_ _| _ \/ __| | | |_ _|_   _/ __| 
// | |/ / |_ \ |) | | (__ | ||   / (__| |_| || |  | | \__ \ 
// |_/___|___/___/   \___|___|_|_\\___|\___/|___| |_| |___/ 
// 
// Soru - 7
// 
// Made by Omermendi Omermendi
// License: CC-BY-SA 3.0
// Downloaded from: https://circuits.io/circuits/4679044-soru-7

String komut;
int deg = 0;
int tmp = 0;
int motPin = 6;
// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(9600);
  Serial.println("Program BASLADI");
  DDRD  |= (1 << 7);
  PORTD |= (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);
  PORTB |= (1 << 0) | (1 << 1) | (1 << 2) | (1 << 3);
}
// the loop routine runs over and over again forever:
void loop() {
  while (Serial.available() > 0) {
    komut +=  Serial.readString();
  }
  if(komut == "BASLA"){
    PORTD |= (1 << 7);
    deg = PIND & 0b00111100;
    deg = deg >> 2;
    deg |= (PINB << 4);
    Serial.println(deg);
  }else{
  	komut = "";
  }
  analogWrite(motPin,deg);
}
