
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
