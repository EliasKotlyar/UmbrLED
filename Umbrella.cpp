
#include "Umbrella.h"

Umbrella::Umbrella()
{

}
void Umbrella::setup()
{
  webservice.setup();
}
void Umbrella::loop()
{

}


void Umbrella::webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t payloadlength) {
  webservice.webSocketEvent(num,type,payload,payloadlength);
}
void Umbrella::setWebSocketHandler(WebSocketsServer::WebSocketServerEvent event){
  webservice.setWebSocketHandler(event);
}
