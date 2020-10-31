#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
int motor=3;
void setup(){
  lcd.begin(20,4);
  Serial.begin(9600);// initialize serial communication  at 9600 bits per second
  pinMode (motor,OUTPUT);lcd.setCursor(0,0);
  lcd.print("Simulasi Kamar Meu");
}
// the loop routine runs over and over again forever:
void loop() {  
  int TEMP_VALUE=Serial.read();
  lcd.setCursor(0,1);
  lcd.print("Temperature:");
  lcd.setCursor(13,1);
  lcd.print(TEMP_VALUE);// print temperature value on LCD 
  if (TEMP_VALUE >= 29){
    digitalWrite(motor,HIGH);
    lcd.setCursor(0,2);
    lcd.print("KIPAS NYALA BRO");
  }else{
    digitalWrite(motor,LOW);
    lcd.setCursor(0,2);
    lcd.print("KIPAS MATIIN BRO");
  }delay(100);    // delay in between reads for stability}
}
