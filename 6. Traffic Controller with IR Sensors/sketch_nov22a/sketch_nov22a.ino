// Define Pin Numbers for IR Sensors (Inputs)
const int IR_North = 2;
const int IR_East = 3;
const int IR_South = 4;
const int IR_West = 5;

// Define Pin Numbers for LEDs (Outputs)
const int LED_North_Green = 6;
const int LED_North_Red = 7;
const int LED_East_Green = 8;
const int LED_East_Red = 9;
const int LED_South_Green = 10;
const int LED_South_Red = 11;
const int LED_West_Green = 12;
const int LED_West_Red = 13;

void setup() {
  Serial.begin(9600);

  // Set IR Sensor pins as INPUT
  pinMode(IR_North, INPUT);
  pinMode(IR_East, INPUT);
  pinMode(IR_South, INPUT);
  pinMode(IR_West, INPUT);

  // Set LED pins as OUTPUT
  pinMode(LED_North_Green, OUTPUT);
  pinMode(LED_North_Red, OUTPUT);
  pinMode(LED_East_Green, OUTPUT);
  pinMode(LED_East_Red, OUTPUT);
  pinMode(LED_South_Green, OUTPUT);
  pinMode(LED_South_Red, OUTPUT);
  pinMode(LED_West_Green, OUTPUT);
  pinMode(LED_West_Red, OUTPUT);

  // Initially turn off all LEDs
  digitalWrite(LED_North_Green, LOW);
  digitalWrite(LED_North_Red, LOW);
  digitalWrite(LED_East_Green, LOW);
  digitalWrite(LED_East_Red, LOW);
  digitalWrite(LED_South_Green, LOW);
  digitalWrite(LED_South_Red, LOW);
  digitalWrite(LED_West_Green, LOW);
  digitalWrite(LED_West_Red, LOW);
}

void loop() {
  // Read IR Sensor States
  bool northActive = digitalRead(IR_North);
  bool eastActive = digitalRead(IR_East);
  bool southActive = digitalRead(IR_South);
  bool westActive = digitalRead(IR_West);

  // Debugging: Print sensor states to Serial Monitor
  Serial.print("North: ");
  Serial.print(northActive);
  Serial.print(" | East: ");
  Serial.print(eastActive);
  Serial.print(" | South: ");
  Serial.print(southActive);
  Serial.print(" | West: ");
  Serial.println(westActive);

  if (northActive || southActive) {
    digitalWrite(LED_North_Green, HIGH);
    digitalWrite(LED_North_Red, LOW);
    digitalWrite(LED_South_Green, HIGH);
    digitalWrite(LED_South_Red, LOW);
    digitalWrite(LED_East_Green, LOW);
    digitalWrite(LED_East_Red, HIGH);
    digitalWrite(LED_West_Green, LOW);
    digitalWrite(LED_West_Red, HIGH);
    Serial.println("North/South Traffic Flow");
  }
  
  else if (eastActive || westActive) {
    
    digitalWrite(LED_East_Green, HIGH);
    digitalWrite(LED_East_Red, LOW);
    digitalWrite(LED_West_Green, HIGH);
    digitalWrite(LED_West_Red, LOW);
    digitalWrite(LED_North_Green, LOW);
    digitalWrite(LED_North_Red, HIGH);
    digitalWrite(LED_South_Green, LOW);
    digitalWrite(LED_South_Red, HIGH);
    Serial.println("East/West Traffic Flow");
  }
  
  else {
    
    digitalWrite(LED_North_Green, LOW);
    digitalWrite(LED_North_Red, HIGH);
    digitalWrite(LED_South_Green, LOW);
    digitalWrite(LED_South_Red, HIGH);
    digitalWrite(LED_East_Green, LOW);
    digitalWrite(LED_East_Red, HIGH);
    digitalWrite(LED_West_Green, LOW);
    digitalWrite(LED_West_Red, HIGH);
    Serial.println("All Directions Red (No Activity)");
  }

  
  delay(100);
}