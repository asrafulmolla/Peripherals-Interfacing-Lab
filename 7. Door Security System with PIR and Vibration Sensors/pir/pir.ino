#include <LiquidCrystal.h>

const int rs = 11, en = 10, d4 = 3, d5 = 2, d6 = 1, d7 = 0;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int ledr = 12;
const int ledy = 13;
const int pirsensor = 5;
const int virsensor = 4;

void setup() {
  pinMode(ledr, OUTPUT);
  pinMode(ledy, OUTPUT);
  pinMode(pirsensor, INPUT);
  pinMode(virsensor, INPUT);

  lcd.begin(16, 2); 
  lcd.clear();
  lcd.print("System Ready");
  delay(1000);
}

void loop() {
  int pir = digitalRead(pirsensor);
  int vir = digitalRead(virsensor);

  if (vir == HIGH) {
    lcd.clear();
    lcd.print("Door vibration");

    digitalWrite(ledr, HIGH);
    delay(200);
    digitalWrite(ledr, LOW);
    delay(200);
    digitalWrite(ledy, LOW);
  }
  else if (pir == HIGH) {
    lcd.clear();
    lcd.print("Object Detected");

    digitalWrite(ledy, HIGH);
    delay(200);
    digitalWrite(ledy, LOW);
    delay(200);
    digitalWrite(ledr, LOW);
  }
  else {
    lcd.clear();
    lcd.print("No Object");
    lcd.setCursor(0, 1);
    lcd.print("Detected");

    digitalWrite(ledy, LOW);
    digitalWrite(ledr, LOW);
  }

  delay(500); 
}