/*  
      OUR SOCIAL NETWORK:
  YOUTUBE : STEAM BINH LONG CLUB
  FACEBOOK: STEAM BINH LONG CLUB
  WEBSITE : http://blsteam.tk
*/
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16,2);
int button = 3;
int red = 4, green = 5, blue = 6;
int btnValue = 0;
int count = 0;
String redStatus = "OFF", greenStatus = "OFF", blueStatus = "OFF";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  pinMode(button, INPUT_PULLUP);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  lcd_default();
}

void loop() {
  // put your main code here, to run repeatedly:
  btnValue = digitalRead(button);
  if(btnValue == 1)
  {
    count++;
  }
  lcd_status();
  led_condition();
  delay(300);
}

void led_condition()
{
  if(count == 0)
  {
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    digitalWrite(blue, LOW); 
    redStatus = "OFF";
    greenStatus = "OFF";
    blueStatus = "OFF";
  }
  else if(count == 1)
  {
    digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
    digitalWrite(blue, LOW); 
    redStatus = "ON ";
    greenStatus = "OFF";
    blueStatus = "OFF";
  }
  else if(count == 2)
  {
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);
    digitalWrite(blue, LOW); 
    redStatus = "OFF";
    greenStatus = "ON ";
    blueStatus = "OFF";
  }
  else if(count == 3)
  {
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    digitalWrite(blue, HIGH);
    redStatus = "OFF";
    greenStatus = "OFF";
    blueStatus = "ON ";
  }
  else if(count < 0 || count > 3)
  {
    count = 0;
  }
}

void lcd_status()
{
  lcd.setCursor(4, 0);
  lcd.print(redStatus);
  lcd.setCursor(13, 0);
  lcd.print(blueStatus);
  lcd.setCursor(7, 1);
  lcd.print(greenStatus);
}

void lcd_default()
{
  lcd.setCursor(0, 0);
  lcd.print("Red: ");
  lcd.setCursor(8, 0);
  lcd.print("Blue: ");
  lcd.setCursor(0, 1);
  lcd.print("Green: ");
}