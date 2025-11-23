void setup() {
  for (int i = 0; i < 14; i++) {
    pinMode(i, OUTPUT);
  }
}
\
void loop() {
  for (int i = 1; i <= 99; i++) {
    printNumber(i);
  }
}

void printNumber(int num) {
  int tens = num / 10;
  int units = num % 10;

  // Display tens digit first (for numbers >= 10)
  if (tens > 0) {
    switch (tens) {
      case 1: oneTens(); break;
      case 2: twoTens(); break;
      case 3: threeTens(); break;
      case 4: fourTens(); break;
      case 5: fiveTens(); break;
      case 6: sixTens(); break;
      case 7: sevenTens(); break;
      case 8: eightTens(); break;
      case 9: nineTens(); break;
    }
    delay(200);
  } else {
    // For numbers < 10, clear tens display
    for (int i = 7; i < 14; i++) {
      digitalWrite(i, LOW);
    }
  }

  // Display units digit
  switch (units) {
    case 0: zero(); break;
    case 1: one(); break;
    case 2: two(); break;
    case 3: three(); break;
    case 4: four(); break;
    case 5: five(); break;
    case 6: six(); break;
    case 7: seven(); break;
    case 8: eight(); break;
    case 9: nine(); break;
  }
  delay(200);
}

void one()
{

  for (int i=0;i<7;i++)
  {
    if (i == 1 || i==2)
      digitalWrite(i,HIGH);
    else 
      digitalWrite(i,LOW);
  }
}

void two()
{
  for (int i=0;i<7;i++)
  {
    if (i == 0 || i == 1 || i==3 || i == 4 || i == 6)
      digitalWrite(i,HIGH);
    else 
      digitalWrite(i,LOW);
  }
}

void three()
{
  for (int i=0;i<7;i++)
  {
    if (i == 0 || i == 1 || i==2 || i == 3 || i == 6)
      digitalWrite(i,HIGH);
    else 
      digitalWrite(i,LOW);
  }
}

void four()
{
  for (int i=0;i<7;i++)
  {
    if (i == 1 || i == 2 || i==5 || i == 6)
      digitalWrite(i,HIGH);
    else 
      digitalWrite(i,LOW);
  }
}

void five()
{
  for (int i=0;i<7;i++)
  {
    if (i == 0 || i == 5 || i==2 || i == 6 || i == 3)
      digitalWrite(i,HIGH);
    else 
      digitalWrite(i,LOW);
  }
}

void six()
{
  for (int i=0;i<7;i++)
  {
    if (i == 0 || i==2 || i == 3 || i == 4 || i==5 || i==6)
      digitalWrite(i,HIGH);
    else 
      digitalWrite(i,LOW);
  }
}

void seven()
{
  for (int i=0;i<7;i++)
  {
    if (i == 0 || i==1 || i == 2)
      digitalWrite(i,HIGH);
    else 
      digitalWrite(i,LOW);
  }
}

void eight()
{
  for (int i=0;i<7;i++)
  {
      digitalWrite(i,HIGH);
  }
}

void nine()
{
  for (int i=0;i<7;i++)
  {
    if (i == 0 || i==1 || i == 2 || i == 3 || i==5 || i==6)
      digitalWrite(i,HIGH);
    else 
      digitalWrite(i,LOW);
  }
}

void zero()
{
  for (int i=0;i<7;i++)
  {
    if (i == 0 || i==1 || i == 2 || i == 3 || i==4 || i==5)
      digitalWrite(i,HIGH);
    else 
      digitalWrite(i,LOW);
  }
}


void oneTens() {
  for (int i=7; i<14; i++) 
  digitalWrite(i, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
}

void twoTens() {
  for (int i=7; i<14; i++) 
  digitalWrite(i, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(13, HIGH);
}

void threeTens() {
  for (int i=7; i<14; i++) 
  digitalWrite(i, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(13, HIGH);
}

void fourTens() {
  for (int i=7; i<14; i++) 
  digitalWrite(i, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(13, HIGH);
}

void fiveTens() {
  for (int i=7; i<14; i++) 
  digitalWrite(i, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(13, HIGH);
}

void sixTens() {
  for (int i=7; i<14; i++) 
  digitalWrite(i, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(13, HIGH);
}

void sevenTens() {
  for (int i=7; i<14; i++) 
  digitalWrite(i, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
}

void eightTens() {
  for (int i=7; i<14; i++) 
  digitalWrite(i, HIGH);
}

void nineTens() {
  for (int i=7; i<14; i++) 
  digitalWrite(i, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(13, HIGH);
}

void zeroTens() {
  for (int i=7; i<14; i++) 
  digitalWrite(i, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);
}
