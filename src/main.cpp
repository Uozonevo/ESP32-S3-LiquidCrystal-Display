#include <Arduino.h>

/* Libraries for LCD Module */
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

/* Define dimensions for LCD */
const int col = 16;
const int row = 2;

/* Create LCD object */
LiquidCrystal_I2C lcd(0x27, col, row);

/* Message strings */
String staticMessage = "String";
String scrollingMessage = "This is the scrolling message that is more than 16 characters";

/**
 * Function to scroll message
 * 
 * Accepts the following arguments:
 * row:       which row on which the scrolling message will be displayed
 * message:   the text that will scroll
 * delayTime: delay between each character shift
 * col:       number of columns on LCD
 */
void scrollText(int row, String message, int delayTime, int col){
  for (int i = 0; i < col; i++){
    message += " ";
  }
  message += " ";

  for (int pos = 0; pos < message.length(); pos++){
    lcd.setCursor(0,row);
    lcd.print(message.substring(pos, pos + col));
    delay(delayTime);
  }
}

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
  /* Print text */
  lcd.print(staticMessage);
  /* Print scrolling text */
  scrollText(1, scrollingMessage, 250, col);
}