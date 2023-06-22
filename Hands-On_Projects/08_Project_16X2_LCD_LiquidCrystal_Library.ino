/*
 * Author: DIBYENDU BARMAN
 * Date: 22-June-2023
 * Project Description: 4 bit 16x2 LCD Display using LiquidCrystal Library
 */

#include<LiquidCrystal.h>

const int RS = 13, EN = 12, D4 = 11, D5 = 10, D6 = 9, D7 = 8;

LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

void setup() {
  lcd.begin(16,2); // Initialize display size 16 column and 2 row
  lcd.setCursor(0,0); // set the cursor position first row first column
  lcd.print("Embedded System"); // Displaying the string
  //lcd.setCursor(0,1); // set the cursor position second row first column
  //lcd.print("Dibyendu Barman"); // Displaying the string
  //delay(5000);
  //lcd.clear(); // clear the full display

}

void loop() {
  /*
  lcd.display();
  delay(1000);
  lcd.noDisplay();
  delay(1000);
  */
  //lcd.scrollDisplayLeft();
  //lcd.scrollDisplayRight();
  //delay(300);
}
