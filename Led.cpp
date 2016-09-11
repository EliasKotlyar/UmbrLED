
#include "Led.h"

Led::Led(void)
{


}
void Led::setup()
{
  FastLED.addLeds<CHIPSET, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalSMD5050 );
  FastLED.setBrightness( BRIGHTNESS );
}
void Led::loop()
{
  FastLED.show();
  FastLED.delay(500);
}

void Led::setAlltoWhite(){
  for(int i = 0;i< NUM_LEDS;i++){
    leds[i] = CRGB::Red;
  }
}

void Led::setColor(int i,uint8_t red,uint8_t green,uint8_t blue){
  leds[i].r = red;
  leds[i].g = green;
  leds[i].b = blue;
}
