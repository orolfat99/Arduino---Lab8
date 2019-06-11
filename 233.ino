#include <Ultrasonic.h>
#include <LiquidCrystal.h>
#define TRIGGER_PIN 10
#define ECHO_PIN 9
LiquidCrystal lcd(12,11,5,4,3,2);
Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);
void setup()
{
  pinMode(6,INPUT_PULLUP);
  lcd.begin(16,2);
  attachInterrupt(6,int0,RISING);
  
}
void loop()
{
  
}
void int0()
{
  lcd.clear();
  float cmMsec,inMsec;
  long microsec=ultrasonic.timing();
  cmMsec=ultrasonic.convert(microsec,Ultrasonic::CM);
  lcd.print("cm:");
  lcd.print(cmMsec);
  delay(500);
}
