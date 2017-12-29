//  _ ___ _______     ___ ___ ___  ___ _   _ ___ _____ ___ 
// / |_  )__ /   \   / __|_ _| _ \/ __| | | |_ _|_   _/ __| 
// | |/ / |_ \ |) | | (__ | ||   / (__| |_| || |  | | \__ \ 
// |_/___|___/___/   \___|___|_|_\\___|\___/|___| |_| |___/ 
// 
// Soru - 1
// 
// Made by Omermendi Omermendi
// License: CC-BY-SA 3.0
// Downloaded from: https://circuits.io/circuits/4634054-soru-1

// the setup routine runs once when you press reset:

volatile int say 	= -1;
volatile int durum 	= 0;
float v = 0.0;
const int potPin = A0;
int potDeg = 0;
const int motPin = 5;
int motDeg = 0;

void setup() {
  // initialize the digital pin as an output.
  Serial.begin(9600);
  DDRB 	|= (1 << 4);
  DDRD  |= (1 << 5);
  PORTD |= (1 << 2);
  attachInterrupt(0,fonk,RISING);
  cli();
  TCCR1B = 0;
  TCCR1A = 0;
  TCNT1 = 3036;
  TCCR1B |= (1 << CS12);
  TIMSK1 |= (1 << TOIE1);
  sei();
  Serial.println("Program BASLADI");
}

ISR(TIMER1_OVF_vect){
  say = 0;
  TCNT1 = 3036;
}

void fonk(){
  say++;
  if(say == 3){
  	durum = !durum;
    say = 0;
  }
  digitalWrite(12,durum);
}

// the loop routine runs over and over again forever:
void loop() {
  if(durum){
    potDeg = analogRead(potPin);
    motDeg = map(potDeg,0,1023,0,255);
    analogWrite(motPin,motDeg);
    v = motDeg*5.0/255;
    Serial.println(v);
  }else{
    analogWrite(motPin,0);  
  }
}
