#include<LiquidCrystal.h>

LiquidCrystal lcd(2,3,4,5,6,7);

void setup()
{
                         
 lcd.begin(16, 2);
  lcd.print("    WELCOME   ");
  lcd.setCursor(0,1);
  lcd.print("   TO MY HOME   ");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  
  delay(1000);
   
  
}
void loop()
{
  lcd.clear();
  String myString = " THIS IS K.VIJAYA BHASKAR REDDY ";
  lcd.setCursor(0,0);
  lcd.print(myString);
  
for (int scrollCounter = 0; scrollCounter < 65; scrollCounter++)
  {

    lcd.scrollDisplayRight();

    delay(250);
  }

  lcd.clear();
}
