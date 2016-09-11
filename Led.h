#include <Arduino.h>
#include <Hash.h>
#define FASTLED_INTERNAL 1
#include <FastLED.h>

#ifndef __INC_LED
#define __INC_LED



const int numberOfVirtualStrips = 40;
const int numberOfPhysicalStrips = 1;
const int pointsPerStrip = 15;




#define LED_PIN     12

#define NUM_LEDS    pointsPerStrip
#define CHIPSET     WS2812B
#define COLOR_ORDER GRB
  //CRGB leds[NUM_LEDS];
#define BRIGHTNESS  128

class Led
{
  public:

    Led(void);
    void setup(void);
    void loop(void);
    void setAlltoWhite(void);
    void setColor(int i,uint8_t red,uint8_t green,uint8_t blue);

  private:
    CRGB leds[NUM_LEDS];
};

#endif
