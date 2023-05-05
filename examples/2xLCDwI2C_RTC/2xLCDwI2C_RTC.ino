/* 2xLCDwI2C_RTC

#  Maintainer & Author
Maintainer: Turkish Technology Team (T3) Foundation (https://deneyapkart.org/)
Author: Dogus Cendek (https://github.com/DogushC)

#  Description
Display scrolling texts on the first LCD screen. Get the current date and time using DS3231 RTC modele and display on the second LCD screen.

#  Hardware Components
1 x Deneyap Kart
2 x 2x16 LCD
2 x I2C LCD Controller
1 x DS3231 RTC Module
1 x Breadboard
1 x Micro-B USB Cable

#  Library
Add "LiquidCrystal_I2C" Library version 1.1.2 by Marco Schwartz and Frank de Brabander (https://github.com/johnrickman/LiquidCrystal_I2C)
Add "RTClib" Library version 2.1.1 by Adafruit (https://github.com/adafruit/RTClib)
*/

#include <LiquidCrystal_I2C.h> //LCD with I2C controller lib
#include <RTClib.h> //RTClib lib

LiquidCrystal_I2C lcd1(0x26, 16, 2); //1.lCD screen config
LiquidCrystal_I2C lcd2(0x27, 16, 2); //2.lCD screen config

RTC_DS3231 rtc; //RTC config

/* Set the date */
String allDate(const DateTime& dt) {
char rtcdate[12];
sprintf(rtcdate, "%02d/%02d/%04d", dt.day(), dt.month(), dt.year());
return String(rtcdate);
}

/* Set the time */
String allTime(const DateTime& dt) {
char rtctime[10];
sprintf(rtctime, "%02d:%02d:%02d", dt.hour(), dt.minute(), dt.second());
return String(rtctime);
}

void setup() {
  lcd1.init(); //initialize 2 rows x 16 columns 1.LCD screen
  lcd1.backlight(); //turn the backlight of 1.LCD screen on
  lcd1.clear(); //clear display and set cursor position to (0,0) of 1.LCD screen

  lcd2.init(); //initialize 2 rows x 16 columns 2.LCD screen
  lcd2.backlight(); //turn the backlight of 2.LCD screen on
  lcd2.clear(); //clear display and set cursor position to (0,0) of 2.LCD screen

  rtc.begin(); //start I2C for DS3231 RTC module
  rtc.adjust(DateTime(__DATE__, __TIME__)); //adjust date and time
}

void loop() {
   DateTime now = rtc.now(); //get the current date and time
   lcd1.setCursor(0, 0); //set the initial location of written text
   lcd1.print((String("Tarih:") + String(allDate(now)))); //print text to the 1.LCD screen
   lcd1.setCursor(0, 1); //set the initial location of written text
   lcd1.print((String("Saat:") + String(allTime(now)))); //print text to the 1.LCD screen

   lcd2.setCursor(2,0); //set the initial location of written text
   lcd2.print("Deneyap Kart"); //print text to the 2.LCD screen
   lcd2.setCursor(1,1); //set the initial location of written text
   lcd2.print("T3 Foundation"); //print text to the 2.LCD screen
   for (int i = 1; i < 14; i++) {
      lcd1.scrollDisplayRight(); //scroll the display to right
      delay(250);
    }
   for (int j = 1; j < 14; j++) {
     lcd1.scrollDisplayLeft(); //scroll the display to left
     delay(250);
   }
}
