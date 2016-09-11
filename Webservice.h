
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <WebSocketsServer.h>
#include "Led.h"
class Webservice
{
  public:

    Webservice(void);
    void setup(void);
    void loop(void);
    void webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t payloadlength);
    void setWebSocketHandler(WebSocketsServer::WebSocketServerEvent event);
    void setLed(Led l);
    void getStripIndexFromRad(float radiant);
    void setLEDColorsForStrip(int index);
  private:
    const char *ssid = "UmbrLED";
    const char *password = "magicmagic";
    WebSocketsServer webSocket = WebSocketsServer(81);
    byte pubpayload[450];
    Led led;
    const int numberOfVirtualStrips = 40;
    const int numberOfPhysicalStrips = 1;
    const int pointsPerStrip = 15;

};
