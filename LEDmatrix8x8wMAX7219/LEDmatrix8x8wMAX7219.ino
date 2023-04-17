/* LEDmatrix8x8wMAX7219

#  Maintainer & Author
Maintainer: Turkish Technology Team (T3) Foundation (https://deneyapkart.org/)
Author: Dogus Cendek (https://github.com/DogushC)

#  Description
Display numbers from 0 to 9 and letters of "DENEYAP".

#  Hardware Components
1 x Deneyap Kart
1 x 8x8 LED Matrix Module with MAX7219
1 x Breadboard
1 x Micro-B USB Cable

#  Library
Add manually "MAX7219DotMatrix" Library by Anas Kuzechie (https://github.com/akuzechie/MAX7219-8x8-Dot-Matrix-Display)
*/

#include <MAX7219DotMatrix.h> //add LED Matrix lib manually

/* Pins for 8x8 LED Matrix */
#define DIN     MOSI
#define CS      D0
#define CLK     SCK

MAX7219DotMatrix disp(DIN, CS, CLK); //LED Matrix config

/* Function for filling display line by line from right to left */
void fill_display()
{
  for(byte i=1; i<=8; i++)
  {
    byte j = 0;
    while(j <= 127)
    {
      j = j*2 + 1;
      disp.Byte(i, j);
      delay(50);
    }
  }
}

void setup()
{
    disp.Init(1); //set brightness level 1 (1-->15)
    disp.Clear(); //clear display
    delay(400);
}

void loop()
{
    for(byte i=0; i<=9; i++) //display numbers from 0 to 9
    {
    disp.Number(i);
    delay(400);
    }
    disp.Clear();
    delay(400);

    fill_display(); //call the "fill_display" function
    disp.Clear();
    delay(400);

    disp.Letter('D'); //display "D" letter
    delay(400);
    disp.Letter('E');
    delay(400);
    disp.Letter('N');
    delay(400);
    disp.Letter('E');
    delay(400);
    disp.Letter('Y');
    delay(400);
    disp.Letter('A');
    delay(400);
    disp.Letter('P');
    delay(400);
    disp.Clear();
    delay(400);

    fill_display();
    disp.Clear();
    delay(400);
}
