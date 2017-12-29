//  _ ___ _______     ___ ___ ___  ___ _   _ ___ _____ ___ 
// / |_  )__ /   \   / __|_ _| _ \/ __| | | |_ _|_   _/ __| 
// | |/ / |_ \ |) | | (__ | ||   / (__| |_| || |  | | \__ \ 
// |_/___|___/___/   \___|___|_|_\\___|\___/|___| |_| |___/ 
// 
// Soru - 6 - ORJ
// 
// Made by Omermendi Omermendi
// License: CC-BY-SA 3.0
// Downloaded from: https://circuits.io/circuits/4835873-soru-6-orj

int LDR = A0;
int deg = 0;
float vOut  = 0;
float ldrR	= 0;
const int R = 270;
String komut;
// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  Serial.begin(9600);
  DDRD |= (1 << 3);
  Serial.println("Program BASLADI");
}

// the loop routine runs over and over again forever:
void loop() {
  while (Serial.available() > 0){
    komut += Serial.readString();
  }
  if(komut == "BASLA"){    
    deg = analogRead(LDR);
    vOut = (deg*5.0)/1023;
    ldrR = ((5.0 - vOut)/(vOut/R));
    analogWrite(3,map(deg,667,1021,0,255));
  	Serial.print("LDR Gerilimi :");
  	Serial.print(vOut);
    Serial.print(" V , LDR Direnci = ");
    Serial.print(ldrR);
    Serial.println(" ohm");
    
  	delay(150);
  }else{
    komut = "";  
  }
}
