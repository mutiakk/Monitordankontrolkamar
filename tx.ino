#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
int TEMP_SENSOR=A0;
void setup(){
  lcd.begin(20,4);
  Serial.begin(9600);// initialize serial communication  at 9600 bits per second
  lcd.setCursor(0,0);
  lcd.print("Simulasi Kamar Meu");
}
void loop() {
  int TEMP_SENSOR_ADC_VALUE = analogRead(TEMP_SENSOR);
  int TEMP_VAL=TEMP_SENSOR_ADC_VALUE/2;
  //10mV/0C is resolution of sensor
  lcd.setCursor(0,1);
  lcd.print("Temp. in 0C:");
  lcd.setCursor(13,1);
  lcd.print(TEMP_VAL);
  // print temperature value on LCD
  Serial.write(TEMP_VAL);
  delay(100);
}
