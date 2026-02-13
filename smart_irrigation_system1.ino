#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

int water; // Variable to store moisture level
LiquidCrystal_I2C lcd(0x27, 16, 2); // Address of the I2C LCD and its dimensions

void setup() {
  pinMode(3, OUTPUT); // Output pin for relay board, this will send signal to the relay
  pinMode(6, INPUT); // Input pin coming from soil sensor
  lcd.init(); // Initialize the LCD
  lcd.backlight(); // Turn on the backlight
}

void loop() {
  water = digitalRead(6); // Reading the signal from the soil sensor
  if (water == HIGH) { // If water level is full then cut the relay
    digitalWrite(3, LOW); // Low is to cut the relay
  } else {
    digitalWrite(3, HIGH); // High to continue providing signal and water supply
  }
  
  // Display moisture level and motor state on LCD
  lcd.clear(); // Clear the LCD
  
  lcd.setCursor(0, 0); // Set cursor to first row
  lcd.print("Moisture: "); // Print label
  lcd.print(water == HIGH ? "Dry" : "Wet"); // Print moisture level
  
  lcd.setCursor(0, 1); // Set cursor to second row
  lcd.print("Motor: "); // Print label
  lcd.print(water == HIGH ? "on" : "off"); // Print motor state
  
  delay(400); // Delay for stability
}