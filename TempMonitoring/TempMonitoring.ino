/*
  Project: Temperature Monitoring for Controlled Environment
  Author: Ashwini Shinde
*/


// Libraries
#include <Wire.h>
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// Define Pins According to Circuit
#define DHTPIN 10
#define DHTTYPE DHT22  // Define the type of DHT sensor (DHT11 or DHT22)
#define redLEDPin 13
#define greenLEDPin 11
#define buzzerPin 12

// Create a DHT object
DHT dhtObject(DHTPIN, DHTTYPE);

LiquidCrystal_I2C lcd(0x27, 20, 4); // Initialize the LCD object with its I2C address and dimensions
const byte ROWS = 4;
const byte COLS = 4;
float lowerTempLimit = 00.0;
float upperTempLimit = 00.0;
char hexaKeys[ROWS][COLS] = {
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};
byte rowPins[ROWS] = { 9, 8, 7, 6 };
byte colPins[COLS] = { 5, 4, 3, 2 };
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() {
  pinMode(redLEDPin, OUTPUT);    // Set red LED pin as output
  pinMode(greenLEDPin, OUTPUT);  // Set green LED pin as output
  Serial.begin(9600);
  dhtObject.begin();
  lcd.backlight();  // Turn on the LCD backlight
  lcd.init();       // Initialize the LCD
  lcd.setCursor(0, 0);
  lcd.print("Welcome User!");
  delay(2000);
  lcd.clear();
  setTemperatureLimits();  // Call the function to set temperature limits
}

void loop() {
  float temp = dhtObject.readTemperature();  // Read the current temperature from the DHT sensor

  lcd.setCursor(0, 1);
  lcd.print("Current Temp: ");
  lcd.print(temp);
  lcd.print(" C");

  lcd.setCursor(0, 2);
  lcd.print("Lower Limit: ");
  lcd.print(lowerTempLimit);
  lcd.print("C");

  lcd.setCursor(0, 3);
  lcd.print("Upper Limit: ");
  lcd.print(upperTempLimit);
  lcd.print("C");

  // Compare temperature with limits and take action if necessary
  if ((temp > upperTempLimit) || (temp < lowerTempLimit) ) {
    // Temperature exceeds upper limit or is below lower limit
    lcd.setCursor(0, 0);
    lcd.print("Limit Exceed !");
    Serial.println("Limit Exceed");
    digitalWrite(buzzerPin, HIGH);    // Turn on the buzzer
    digitalWrite(redLEDPin, HIGH);    // Turn on the red LED
    delay(2000);
    digitalWrite(buzzerPin, LOW);     // Turn off the buzzer
    digitalWrite(redLEDPin, LOW);     // Turn off the red LED

  } else {
    lcd.setCursor(0, 0);
    lcd.print("Temp OK !");
    Serial.println("Temp OK");
    digitalWrite(greenLEDPin, HIGH);  // Turn on the green LED
    delay(2000);
    digitalWrite(greenLEDPin, LOW);   // Turn off the green LED
  }
}

void setTemperatureLimits() {
  char storeDigit[2];
  int digitCount = 0;

  lcd.print("Set Limits");
  lcd.setCursor(0, 1);
  lcd.print("Lower Limit: ");
  char key = customKeypad.getKey();

  while (digitCount < 2) {
    char key = customKeypad.getKey();
    if (key) {
      storeDigit[digitCount] = key;
      digitCount++;
      lcd.print(key);
      delay(200);
    }
  }

  lowerTempLimit = atof(storeDigit);  // Convert the stored digits to a floating-point lower temperature limit
  key = '\0';                         // Reset the key value
  storeDigit[2] = '\0';                // Reset the stored digits
  digitCount = 0;
  lcd.setCursor(0, 2);
  lcd.print("Upper Limit: ");

  while (digitCount < 2) {
    char key = customKeypad.getKey();
    if (key) {
      storeDigit[digitCount] = key;
      digitCount++;
      lcd.print(key);
      delay(200);
    }
  }

  upperTempLimit = atof(storeDigit);  // Convert the stored digits to a floating-point upper temperature limit

  delay(500);
  lcd.clear();
}
