
#include "Umbrella.h"

Umbrella::Umbrella()
{

}
void Umbrella::setup()
{
  Serial.begin(115200);
  sensor.setup();
  webservice.setup();
  led.setup();
  led.setAlltoWhite();
}
void Umbrella::loop()
{
  sensor.loop();
  led.loop();
  webservice.loop();
  Serial.print("  \tZ: "); Serial.print(sensor.getAngle());     Serial.println("  \tdps");
  delay(250);
}


void Umbrella::webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t payloadlength) {
  webservice.webSocketEvent(num,type,payload,payloadlength);
}
void Umbrella::setWebSocketHandler(WebSocketsServer::WebSocketServerEvent event){
  webservice.setWebSocketHandler(event);
}
