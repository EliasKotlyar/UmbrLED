#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <WebSocketsServer.h>

class Webservice
{
  public:

    Webservice(void);
    void setup(void);
    void loop(void);
    void webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t payloadlength);
    void setWebSocketHandler(WebSocketsServer::WebSocketServerEvent event);
  private:
    const char *ssid = "UmbrLED";
    const char *password = "magicmagic";
    WebSocketsServer webSocket = WebSocketsServer(81);
    byte pubpayload[450];

};
