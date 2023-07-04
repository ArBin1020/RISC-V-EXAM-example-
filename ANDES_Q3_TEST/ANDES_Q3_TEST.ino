#include <LiquidCrystal.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void setup() {
  lcd.begin(16, 2);
   // Print a message to the LCD.
//  lcd.print("2020 Hello World!");
  lcd.setCursor(0, 1);
  lcd.print("Andes Hello!");
}

void loop() {
  // put your main code here, to run repeatedly:

}
