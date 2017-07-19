#include <LiquidCrystal.h>
#include <Wire.h>
#include <TEA5767Radio.h>
TEA5767Radio radio = TEA5767Radio();
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

float f = 86.0;
float fr;

void setup()
{
  lcd.begin(16,2);
  lcd.clear();
  Serial.begin(9600);
  Wire.begin();
  lcd.print("Dobrodosli");
  delay(2000);
  lcd.clear();
  pinMode(13,OUTPUT);
  digitalWrite(13,HIGH);
}

void loop()
{
  int p = analogRead(A1);
  Serial.println(A1);
  Serial.println(A5);
  int q = p/4;
  fr = f + (0.1*q);
  Serial.println(fr); 
  lcd.setCursor(4,0);
  lcd.print(fr);
  lcd.print("MHz");
  radio.setFrequency(fr);

  if (fr==88.3 || fr==93.3 || fr==92.1 || fr==91.6)
  {
    lcd.setCursor(0,2);
    lcd.print("Hrvatski radio 1");
  }
  else if(fr==91.2 || fr==107.8)
  {
    lcd.setCursor(0,2);
    lcd.print("Otvoreni radio");
  }
  else if(fr==95.3 || fr==93.9 || fr==89.7 || fr==95.6)
  {
    lcd.setCursor(1,2);
    lcd.print("Narodni radio");
  }
  else if(fr==98.6 || fr==104.9 || fr==102.4)
  {
   lcd.setCursor(7,2);
   lcd.print("HKR");
  }
  else if(fr==99.1)
  {
    lcd.setCursor(1,2);
    lcd.print("Gradski radio");
  }
  else if(fr==100.6 || fr==106.2)
  {
    lcd.setCursor(0,2);
    lcd.print("Slavonski radio");
  }
  else if(fr==102.4 || fr==102.8 || fr==105.3 || fr==99.3 || fr==102.0 || fr==105.6)
  {
    lcd.setCursor(2,2);
    lcd.print("Radio Osijek");
  }
  else if(fr==103.4)
  {
    lcd.setCursor(0,2);
    lcd.print("Hrvatski radio 3");
  }
  else if(fr==107.0)
  {
    lcd.setCursor(0,2);
    lcd.print("Slavonski radio");
  }
  else if(fr==98.1 || fr==96.1 || fr==104.4)
  {
    lcd.setCursor(0,2);
    lcd.print("Hrvatski radio 2");
  }
  else if(fr==92.7)
  {
    lcd.setCursor(0,2);
    lcd.print("TotalniFM Osijek");
  }
  else 
  {
    lcd.clear();
  }
}
