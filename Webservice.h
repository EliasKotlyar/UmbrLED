#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <WebSocketsServer.h>

class Webservice
{
  public:

    Webservice(void);
    void setup(void);
    void loop(void);

  private:
    const char *ssid = "UmbrLED";
    const char *password = "magicmagic";
    WebSocketsServer webSocket = WebSocketsServer(81);

};
