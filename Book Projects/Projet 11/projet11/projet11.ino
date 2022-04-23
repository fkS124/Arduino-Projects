#include <LiquidCrystal.h>
#include <TimeLib.h>

LiquidCrystal lcd(12,11,5,4,3,2);
int value = 0;

String texts[] = {"Bonjour monsieur", String(weekday())+" "+String(day())};
String texts2[] = {"nous sommes le :", String(month())+" "+String(year())};

void setup() {
  lcd.begin(16,2); 
  Serial.begin(9600);

  lcd.print(texts[value]);
  lcd.setCursor(0, 1);
  lcd.print(texts2[value]);
}

void loop() {
  
  if (analogRead(A0) > 0 && value < 1) {
    value++;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(texts[value]);
    lcd.setCursor(0, 1);
    lcd.print(texts2[value]);
    delay(200);
  }
}
