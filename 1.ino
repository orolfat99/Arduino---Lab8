#include <Ultrasonic.h>
#include <LiquidCrystal.h>
#define TRIGGER_PIN 10
#define ECHO_PIN 9
LiquidCrystal lcd(12,11,5,4,3,2);
Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);
void setup()
{
  Serial.begin(9600);
  
}
void loop()
{
  float cmMsec, inMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM); // 計算距離，單位: 公分
 
  Serial.print(cmMsec);
  lcd.print(", CM: ");
  lcd.print(cmMsec);
  
  delay(100);
}
