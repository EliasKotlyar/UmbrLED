
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
void Webservice::setWebSocketHandler(WebSocketsServer::WebSocketServerEvent event){
  webSocket.onEvent(event);
}
void Webservice::loop()
{
}
