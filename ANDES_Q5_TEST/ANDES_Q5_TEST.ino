#include <LiquidCrystal.h>
#include <RTC.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
/* Change these values to set the current initial time */
const byte seconds = 0;
const byte minutes = 53;
const byte hours = 15;
const byte day = 19;
void setup() {
  // set up the LCD's number of columns and rows
  lcd.begin(16, 2);
  // set the time and start counting
  RTC.settime(day, hours, minutes, seconds);
  RTC.startcounting();
}
void loop() {
  lcd.clear();
  lcd.print("Start Counting...");
  lcd.setCursor(0, 1);
  lcd.print("21/2/");
  lcd.print(RTC.getday());
  lcd.print(",");
  lcd.print(RTC.gethours());
  lcd.print(":");
  lcd.print(RTC.getminutes());
  lcd.print(":");
  lcd.print(RTC.getseconds());
  
  delay(1000);
}
