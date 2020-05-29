// See LICENSE file for details
// Copyright 2016 Florian Link (at) gmx.de

#include "Laser.h"
#include "Drawing.h"
#include "Cube.h"
#include "Objects.h"
#include "Logo.h"
#include "ilda-decoder.h"

// Create laser instance (with laser pointer connected to digital pin 5) (9 on chichis prepre)
Laser laser(9);

void setup()
{  
  laser.init();
}






// currently unused, some more objects
void drawObjects()
{
  int count = 100;
  laser.setScale(2);
  laser.setOffset(0,3000);

  for (int i = 0;i<count;i++) Drawing::drawObject(draw_plane, sizeof(draw_plane)/4);
  for (int i = 0;i<count;i++) Drawing::drawObject(draw_bike, sizeof(draw_bike)/4);
  for (int i = 0;i<count;i++) Drawing::drawObject(draw_question, sizeof(draw_question)/4);
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
//  ilda_init("Ali.ild");
  drawObjects();
//  drawSaskcirc();

//  drawArduino3D();
//  drawScroller(String("SOURCE CODE AVAILABLE ON GITHUB!"),0.25,2048,100);

//  drawObjects();
//  jumpingText();
}
