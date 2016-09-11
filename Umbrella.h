
#include "Webservice.h"
#include "Led.h"
#include <WebSocketsServer.h>

class Umbrella
{
  public:
    Umbrella(void);
    void setup(void);
    void loop(void);
    void webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t payloadlength);
    void setWebSocketHandler(WebSocketsServer::WebSocketServerEvent event);
  private:
    Webservice webservice;

};
