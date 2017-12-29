//  _ ___ _______     ___ ___ ___  ___ _   _ ___ _____ ___ 
// / |_  )__ /   \   / __|_ _| _ \/ __| | | |_ _|_   _/ __| 
// | |/ / |_ \ |) | | (__ | ||   / (__| |_| || |  | | \__ \ 
// |_/___|___/___/   \___|___|_|_\\___|\___/|___| |_| |___/ 
// 
// Soru - 8
// 
// Made by Omermendi Omermendi
// License: CC-BY-SA 3.0
// Downloaded from: https://circuits.io/circuits/4803059-soru-8

int sayi = 0;
int i = 0;

// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(9600);
  DDRD  |= (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);
  DDRB  |= (1 << 0) | (1 << 1) | (1 << 2) | (1 << 3);
  PORTC |= (1 << 0) | (1 << 1);
  Serial.println("Program BASLADI");
}

// the loop routine runs over and over again forever:
void loop() {
  while(analogRead(A0) == 0){
    if(sayi < 9){
      sayi++;    
    }else{
      i++;
      sayi = 0;
    }
    PORTD = (sayi << 2);
    PORTB = i;
    Serial.println(PORTD);
    delay(500);
  }
  while(analogRead(A1) == 0){
    if(sayi < 1){
      i--;
      sayi = 9;
    }else{
      sayi--;
    }
    PORTD = (sayi << 2);
    PORTB = i;
    delay(500);
  } 
}
