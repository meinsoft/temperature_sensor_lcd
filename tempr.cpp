#define analog A0
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27,20,4);

void setup()
{
    pinMode(analog, INPUT);
    Serial.begin(9600);

    lcd.init();  
    lcd.backlight();   
}

void loop()
{
  int baselineTemp = 40;
  
  int celsius = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);
  
  int fahrenheit = ((celsius * 9) / 5 + 32);
  lcd.print(celsius);
  lcd.print(" C, ");
  lcd.print(fahrenheit);
  lcd.println(" F");
}