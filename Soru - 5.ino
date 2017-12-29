//  _ ___ _______     ___ ___ ___  ___ _   _ ___ _____ ___ 
// / |_  )__ /   \   / __|_ _| _ \/ __| | | |_ _|_   _/ __| 
// | |/ / |_ \ |) | | (__ | ||   / (__| |_| || |  | | \__ \ 
// |_/___|___/___/   \___|___|_|_\\___|\___/|___| |_| |___/ 
// 
// Soru - 5
// 
// Made by Omermendi Omermendi
// License: CC-BY-SA 3.0
// Downloaded from: https://circuits.io/circuits/4653094-soru-5

volatile int durum = 0;
String komut;
int lm35 	   = A0;
float lm35Deg  = 0;
float sicaklik = 0;
float oncekiSicaklik = 0;
// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(9600);
  Serial.println("Program BASLADI");
  DDRB  |= (1 << 0);
  PORTD |= (1 << 2);
  attachInterrupt(0,fonk,FALLING);
}
void fonk(){
  if(durum){
    lm35Deg = analogRead(lm35);
    lm35Deg = (lm35Deg/1023)*5000;
    sicaklik = lm35Deg/10.0;
    Serial.print("Sicaklik : ");
    Serial.print(sicaklik);
    Serial.print(" C , Onceki olcumden ");
    if(sicaklik > oncekiSicaklik){
      oncekiSicaklik = sicaklik - oncekiSicaklik;
      Serial.print(oncekiSicaklik);
      Serial.println(" C daha fazla");
    }else if(sicaklik < oncekiSicaklik){
      oncekiSicaklik = oncekiSicaklik - sicaklik;
      Serial.print(oncekiSicaklik);
      Serial.println(" C daha az");
    }
    oncekiSicaklik = sicaklik;
  }
}
// the loop routine runs over and over again forever:
void loop() {
  while (Serial.available() > 0) {
    komut +=  Serial.readString();
  }
  if(komut == "BASLA"){
    durum = 1;
  }
  PORTB |= (durum << 0);
}
