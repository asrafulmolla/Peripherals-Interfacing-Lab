#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Pad strings with spaces on both sides for smooth scrolling
String line1 = "                hello, world!                "; // 16 spaces before and after
String line2 = "                hello, world!                "; // 16 spaces before and after

int pos1 = 0;                         // scroll position for line1 (start at left)
int pos2 = line2.length() - 16;      // scroll position for line2 (start at right)

int dir1 = 1;  // direction for line1: 1 = left to right, -1 = right to left
int dir2 = -1; // direction for line2: -1 = right to left, 1 = left to right

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  // Print window of 16 characters for line 1
  lcd.setCursor(0, 0);
  lcd.print(line1.substring(pos1, pos1 + 16));

  // Print window of 16 characters for line 2
  lcd.setCursor(0, 1);
  lcd.print(line2.substring(pos2, pos2 + 16));

  // Update positions based on direction
  pos1 += dir1;
  pos2 += dir2;

  // Bounce line1 when it reaches start or end
  if (pos1 <= 0) {
    dir1 = 1;  // change direction to left to right
  } 
  else if (pos1 >= line1.length() - 16) {
    dir1 = -1; // change direction to right to left
  }

  // Bounce line2 when it reaches start or end
  if (pos2 <= 0) {
    dir2 = 1;  // change direction to left to right
  } 
  else if (pos2 >= line2.length() - 16) {
    dir2 = -1; // change direction to right to left
  }

  delay(250); // adjust speed here
}
