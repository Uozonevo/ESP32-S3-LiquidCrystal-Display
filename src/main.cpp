#include <Arduino.h>

/* Libraries for LCD Module */
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

/* Define dimensions for LCD */
const int col = 16;
const int row = 2;

/* Create LCD object */
LiquidCrystal_I2C lcd(0x27, col, row);

void setup()
{
  /* Initialize LCD */
  lcd.init();
  /* Turn on backlight */
  lcd.backlight();
}

void loop()
{
  /* Set the starting cursor position */
  lcd.setCursor(0,0);
  lcd.print("Hello, World!");
  delay(1000);
  lcd.clear();
  /* Clear display */
  lcd.setCursor(0,1);
  lcd.print("Hello, World!");
  delay(1000);
  lcd.clear();
}