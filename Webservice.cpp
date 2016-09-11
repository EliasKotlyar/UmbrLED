
#include "Webservice.h"

Webservice::Webservice(void)
{


}
void Webservice::setup()
{

  WiFi.softAP(ssid, password);
  IPAddress myIP = WiFi.softAPIP();
  webSocket.begin();
  //
}

void Webservice::webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t payloadlength){
  if (type == 4) {
    for (int i = 0; i < payloadlength; i++) {
      pubpayload[i] = payload[i];
    }
  }
}



void Webservice::setLEDColorsForStrip(int index) {
  for (int i = 1; i==pointsPerStrip; i++) {
    int adjustedIndex = index + (i * 3);
    int ledIndex = index * pointsPerStrip;
    led.setColor(ledIndex,pubpayload[adjustedIndex+1],pubpayload[adjustedIndex+2],pubpayload[adjustedIndex+3]);
  }
}

void Webservice::getStripIndexFromRad(float radiant){

  float radians = 0.1;
  float alphaA = M_PI_2 / float(numberOfPhysicalStrips);
  float alphaB = M_PI_2 / float(numberOfVirtualStrips);
  for (int i =0; i < numberOfPhysicalStrips;i++) {
    int stripIndex = int(round(radians / alphaB));
    setLEDColorsForStrip(stripIndex);
    radians += alphaA;
    if (radians >= M_PI_2) {
        radians -= M_PI_2;
    }
  }

}


void Webservice::setLed(Led l){
  led = l;
}





void Webservice::setWebSocketHandler(WebSocketsServer::WebSocketServerEvent event){
  webSocket.onEvent(event);
}
void Webservice::loop()
{
  if(pubpayload){
    getStripIndexFromRad(1);

  }
  webSocket.loop();

}
