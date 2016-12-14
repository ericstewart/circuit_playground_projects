#include <Adafruit_CircuitPlayground.h>

void setup() {
 CircuitPlayground.begin();
}

void christmasColors() {
  // Let's just show some Christmas colors for a few seconds at a time
  for(int i=0; i<4; i++) {
    CircuitPlayground.clearPixels();
  
    delay(500);
    CircuitPlayground.setPixelColor(0, 255,   0,  0);
    CircuitPlayground.setPixelColor(1, 255,   0,  0);
    CircuitPlayground.setPixelColor(2, 255,   0,  0);
    CircuitPlayground.setPixelColor(3, 255,   0,  0);
    CircuitPlayground.setPixelColor(4, 255,   0,  0);
  
    CircuitPlayground.setPixelColor(5, 0,   255,  0);
    CircuitPlayground.setPixelColor(6, 0,   255,  0);
    CircuitPlayground.setPixelColor(7, 0,   255,  0);
    CircuitPlayground.setPixelColor(8, 0,   255,  0);
    CircuitPlayground.setPixelColor(9, 0,   255,  0);
    
    delay(2000);
  }
}

void rainbowCycle() {
  uint32_t stop_time = millis() + 5000;

 // This little snippet borrowed from Adafruit's Circuit Playground Mega Demo
 // https://github.com/adafruit/Adafruit_CircuitPlayground/tree/master/examples/mega_demo/RainbowCycleDemo.h
 
  while(millis() < stop_time) {
   uint32_t offset = millis() / 5;
    // Loop through each pixel and set it to an incremental color wheel value.
    for(int i=0; i<10; ++i) {
      CircuitPlayground.strip.setPixelColor(i, CircuitPlayground.colorWheel(((i * 256 / 10) + offset) & 255));
    }
    // Show all the pixels.
    CircuitPlayground.strip.show();
  }    
  CircuitPlayground.clearPixels();
  delay(2000);

}

void pointsAroundStar() {
  CircuitPlayground.setPixelColor(6, 255,0,255);
  delay(1000);
  CircuitPlayground.setPixelColor(2, 0,   0, 255 );
  delay(1000);
  CircuitPlayground.setPixelColor(8, 0,   255,  0);
  delay(1000);
  CircuitPlayground.setPixelColor(4, 255,   255,  0);
  delay(1000);
  CircuitPlayground.setPixelColor(0, 204,   102,  0);
  delay(1000);
}

void loop() {
  christmasColors();

  rainbowCycle();

  pointsAroundStar();
 } 
