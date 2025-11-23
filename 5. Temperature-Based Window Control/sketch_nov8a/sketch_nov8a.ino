#include<Servo.h>
#include<LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

Servo myservo;
int pos=0;
float tem, vout;

void setup() {
  pinMode (13, OUTPUT);
  pinMode (12, OUTPUT);
  pinMode (A0, INPUT);

  myservo.attach(10);
  myservo.write(0);
  lcd.begin(16,2);  
}

void loop() {

  vout=analogRead (A0);
  tem= (vout*500)/1023;

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(tem);
  lcd.print(" C   ");

  if (tem > 30)
  {
    myservo.write(90);
  }
  else if (tem < 20)
  {
    myservo.write(0);
  }
  else
  {
    digitalWrite(13, LOW);
  }

}
