#include <Arduino.h>
#include <Hash.h>
#define FASTLED_INTERNAL 1
#include <FastLED.h>

const int rows = 15;
#define LED_PIN     12

#define NUM_LEDS    rows
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

  private:
    CRGB leds[NUM_LEDS];
};
