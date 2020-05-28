// See LICENSE file for details
// Copyright 2016 Florian Link (at) gmx.de

#include "Laser.h"
#include "Drawing.h"
#include "Cube.h"
#include "Objects.h"
#include "Logo.h"

// Create laser instance (with laser pointer connected to digital pin 5) (9 on chichis prepre)
Laser laser(9);

void setup()
{  
  laser.init();
}




void drawSaskcirc()
{
//int count = 100;
//  laser.setScale(0.8);
//  laser.setOffset(-100,1100);
//
//  for (int i = 0;i<count;i++) Drawing::drawObject(draw_saskcirc, sizeof(draw_saskcirc)/4);

long centerX, centerY, hX, hY, w,h;
  Drawing::calcObjectBox(draw_saskcirc, sizeof(draw_saskcirc)/4, centerX, centerY, w, h);
  int angle = 0;
  int x = 1400;
  for (;x<4396;) {
    laser.setOffset(x,2048);
    laser.setScale(1.);
    Drawing::drawObjectRotated(draw_saskcirc, sizeof(draw_saskcirc)/4, centerX, centerY, angle % 360);
    angle += 2;
//    x += 4;
  }
  
  
}



void drawWoordclip()
{
int count = 500;
  laser.setScale(0.6);
  laser.setOffset(0,0);

  for (int i = 0;i<count;i++) Drawing::drawObject(draw_woord4, sizeof(draw_woord4)/4);
  
//long centerX, centerY, hX, hY, w,h;
//  Drawing::calcObjectBox(draw_woord4, sizeof(draw_woord4)/4, centerX, centerY, w, h);
//  int angle = 0;
//  int x = 100;
//  for (;x<4396;) {
//    laser.setOffset(x,2048);
//    laser.setScale(1.);
//    Drawing::drawObjectRotated(draw_woord4, sizeof(draw_woord4)/4, centerX, centerY, angle % 360);
//    angle += 2;
//    x += 4;
//   }
}


// arduino + heart
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

// currently unused, some more objects
void drawObjects()
{
  int count = 100;
  laser.setScale(2);
  laser.setOffset(0,0);

  for (int i = 0;i<count;i++) Drawing::drawObject(draw_island, sizeof(draw_island)/4);
  for (int i = 0;i<count;i++) Drawing::drawObject(draw_glasses, sizeof(draw_glasses)/4);
  for (int i = 0;i<count;i++) Drawing::drawObject(draw_smoking, sizeof(draw_smoking)/4);
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
// drawScroller(String("SASKIAN SYNTHETICS"),0.5,2048,100);
//  drawWeLove();
// drawArduino2DRotate();
//  whatAbout3D();
//  rotateCube(400);
  drawWoordclip();
//  drawSaskcirc();

//  drawArduino3D();
//  drawScroller(String("SOURCE CODE AVAILABLE ON GITHUB!"),0.25,2048,100);

//  drawObjects();
//  jumpingText();
}
