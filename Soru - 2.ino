//  _ ___ _______     ___ ___ ___  ___ _   _ ___ _____ ___ 
// / |_  )__ /   \   / __|_ _| _ \/ __| | | |_ _|_   _/ __| 
// | |/ / |_ \ |) | | (__ | ||   / (__| |_| || |  | | \__ \ 
// |_/___|___/___/   \___|___|_|_\\___|\___/|___| |_| |___/ 
// 
// Soru - 2
// 
// Made by Omermendi Omermendi
// License: CC-BY-SA 3.0
// Downloaded from: https://circuits.io/circuits/4794469-soru-2

int lastTime = 0;
int data;
int clk = 0;
int i = 0;
void setup() {
  Serial.begin(9600);
  Serial.println("Program BASLADI");
  DDRB |= (1 << 0) | (1 << 1) | (1 << 2);
}

int getBit(int val,int bit){
	val &= (1 << bit);
	return (val >> bit);
}

// the loop routine runs over and over again forever:
void loop() {
  while (Serial.available() > 0){
    data = Serial.parseInt();
  }
  Serial.println(data);
  if(millis() - lastTime > 250){
    lastTime = millis();
    clk = !clk;
    if(clk && data){
      digitalWrite(8,getBit(data,i));
      digitalWrite(9,!getBit(data,i));
      i++;
    }else if(i > 3){i = 0;}
    digitalWrite(10,clk);
  }
}
