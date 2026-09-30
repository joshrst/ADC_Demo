/*------------------------------------
          ADC Demo
--------------------------------------
 Description:
 
 
 Programmer:
       Yuzon, Maria Rebekah J.
       Manicang, Joshua G.
       
 Date:
 16 September 2026
---------------------------------------*/
// GPIO
const uint8_t POT = 36;
const int LED = 32; 
const int LED_GRN = 25; 
const int LED_YLW = 26; 
const int LED_RED = 27; 

// variable
int pot_val = 0;
const int FREQ = 5000;
const uint8_t RES = 12;

void setup() {
  pinMode(POT, INPUT);
  pinMode(LED_GRN, OUTPUT);
  pinMode(LED_YLW, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  ledcAttach(LED, FREQ, RES);
  Serial.begin(9600);
}

void loop() {
  pot_val = analogRead(POT); 
  ledcWrite(LED, pot_val);   

  
  digitalWrite(LED_GRN, LOW);
  digitalWrite(LED_YLW, LOW);
  digitalWrite(LED_RED, LOW);

  
  if (pot_val < 800) {
    digitalWrite(LED_GRN, HIGH);
    Serial.println("Brightness: Level 1");
  } 
  else if (pot_val > 800 && pot_val < 1500) {
    digitalWrite(LED_YLW, HIGH);
    Serial.println("Brightness: Level 2");
  } 
  else {
    digitalWrite(LED_RED, HIGH);
    Serial.println("Brightness: Level 3");
  }

  delay(500);
}