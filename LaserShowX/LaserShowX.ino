// See LICENSE file for details
// Copyright 2016 Florian Link (at) gmx.de

#include "Laser.h"
#include "Drawing.h"
#include "Cube.h"
#include "Objects.h"
#include "abolish.h"
#include "police.h"
#include "stopcops.h"
#include "blackjoy.h"
#include "fist.h"
#include "pow.h"
#include "2.h"
#include "thepeople.h"
#include "blacklove.h"
#include "ftp.h"
#include "Logo.h"
#include "dog1.h"

// Create laser instance (with laser pointer connected to digital pin 5) (9 on chichis prepre)
Laser laser(9);

void setup()
{  
  laser.init();
}

const unsigned short draw_heart[] PROGMEM = {
0x330,0x23e,
0x82fa,0x192,
0x825a,0xe3,
0x81b4,0x6d,
0x80ea,0x0,
0x80f0,0x29,
0x80f2,0x50,
0x80e3,0xae,
0x80b4,0x103,
0x8079,0x144,
0x803e,0x185,
0x800f,0x1d7,
0x8000,0x231,
0x800f,0x285,
0x803d,0x2c8,
0x8083,0x2f5,
0x80d8,0x303,
0x8115,0x2fb,
0x814d,0x2e2,
0x817e,0x2b9,
0x8198,0x284,
0x81e9,0x2e4,
0x8258,0x303,
0x82a7,0x2f6,
0x82ed,0x2cc,
0x831f,0x28c,
0x8330,0x23e,
0x8330,0x23e,
};

void drawWeLove()
{
  int w1 = Drawing::stringAdvance("saskia");
  long centerX, centerY, w,h;
  Drawing::calcObjectBox(draw_heart, sizeof(draw_heart)/4, centerX, centerY, w, h);

  laser.setOffset(1348,2048);
  long maxMove = 0;
  for (int i = 0;i<300;i++) {
    laser.setMaxMove(maxMove);
    maxMove += 200;
    laser.setScale(0.4);
    Drawing::drawString("saskia",-w1/2, SIN((i*10) % 360)/6.);
    if (i>100) {
      laser.resetMaxMove();
      laser.setScale(2 + SIN((i*10)%360) / 13000.);
      Drawing::drawObject(draw_heart, sizeof(draw_heart)/4, -centerX, -centerY);
    }
    if (i>150) {
      maxMove -= 400;
    }
  }
  laser.resetMaxMove();
}



void circle() {
  const int scale = 12;
  laser.sendto(SIN(0)/scale, COS(0)/scale);
  laser.on();
  for (int r = 5;r<=360;r+=5)
  {    
    laser.sendto(SIN(r)/scale, COS(r)/scale);
  }
  laser.off();
}

// currently unused, some more objects
void drawObjects()
{
  int count = 70;
  laser.setScale(0.8);
  laser.setOffset(00,00);

//    for (int i = 0;i<count;i++) Drawing::drawObject(draw_abolish, sizeof(draw_abolish)/4);
//    for (int i = 0;i<count;i++) Drawing::drawObject(draw_police, sizeof(draw_police)/4);
//    for (int i = 0;i<count;i++) Drawing::drawObject(draw_stopcops, sizeof(draw_stopcops)/4);
    for (int i = 0;i<count;i++) Drawing::drawObject(draw_dog1, sizeof(draw_dog1)/4);    
//    for (int i = 0;i<count;i++) Drawing::drawObject(draw_blacklove, sizeof(draw_blacklove)/4);
//    for (int i = 0;i<count;i++) Drawing::drawObject(draw_blackjoy, sizeof(draw_blackjoy)/4);
//    delay(1000);
//    for (int i = 0;i<count;i++) Drawing::drawObject(draw_fist, sizeof(draw_fist)/4);
//    
//    delay(200);
//    laser.setOffset(00,1300);
//    for (int i = 0;i<count/3;i++) Drawing::drawObject(draw_pow, sizeof(draw_pow)/4);
//    laser.setOffset(00,000);
//    for (int i = 0;i<count/3;i++) Drawing::drawObject(draw_2, sizeof(draw_2)/4);
//    for (int i = 0;i<count/2;i++) Drawing::drawObject(draw_thepeople, sizeof(draw_thepeople)/4);
//    laser.setOffset(00,1300);
//    for (int i = 0;i<count/3;i++) Drawing::drawObject(draw_pow, sizeof(draw_pow)/4);
//    laser.setOffset(00,000);
//    for (int i = 0;i<count/3;i++) Drawing::drawObject(draw_2, sizeof(draw_2)/4);
//    for (int i = 0;i<count/2;i++) Drawing::drawObject(draw_thepeople, sizeof(draw_thepeople)/4);
//    delay(800);
//  for (int i = 0;i<count;i++) Drawing::drawObject(draw_bike, sizeof(draw_bike)/4);
  
}

// draws text as scroller from right to left
void drawScroller(String s, float scale = 0.5, int offsetY = 2048, int speed = 100)
{
  int charW = Drawing::advance('I'); // worst case: smallest char
  int maxChar = (4096. / (charW * scale) );
  // some senseful max buffer, don't use a very small scale...
  char buffer[100];
  for (int j = 0;j<maxChar;j++) {
    buffer[j] = ' ';
  }
  laser.setOffset(0,offsetY);
  laser.setScale(scale);
  int scrollX = 0;
  for (int c = 0; c < s.length() + maxChar; c++) {
    int currentScroll = Drawing::advance(buffer[0]);
    while (scrollX < currentScroll) {
      long time = millis();
      int x = -scrollX;;
      int y = 0;
      bool somethingDrawn = false;
      for (int i = 0;i<maxChar;i++) {
        if (buffer[i] != ' ') {
          somethingDrawn = true;
        }
        x += Drawing::drawLetter(buffer[i], x, y);
        if (x > 4096 / scale) {
          break;
        }
      }
      if (!somethingDrawn) { scrollX = currentScroll; }
      scrollX += speed / scale;
      long elapsed = millis() - time;
      if (elapsed < 50) { delay(50-elapsed); }

    }
    scrollX -= currentScroll;
    for (int k = 0;k<maxChar-1;k++) {
      buffer[k] = buffer[k+1];
    }
    if (c<s.length()) {
      buffer[maxChar-1] = s[c];
    } else{
      buffer[maxChar-1] = ' ';
    }
  }
}


void loop() {
//  countDown();
//  letterEffect();
//  presents();
//  arduino();
//  laserShow();
//  drawPlane();
//  drawLogo();
//  globe(200);
// drawScroller(String("BLACK LIVES MATTER"),0.5,2048,100);
//  drawWeLove();
// drawArduino2DRotate();
//  whatAbout3D();
//  rotateCube(400);
//  ilda_init("Ali.ild");
//circle();
  drawObjects();
//  drawSaskcirc();

//  drawArduino3D();
//  drawScroller(String("SOURCE CODE AVAILABLE ON GITHUB!"),0.25,2048,100);

//  drawObjects();
//  jumpingText();
}
