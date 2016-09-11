
#include "Webservice.h"

Webservice::Webservice(void)
{


}
void Webservice::setup()
{
  
  WiFi.softAP(ssid, password);
  IPAddress myIP = WiFi.softAPIP();
  webSocket.begin();
  webSocket.onEvent(webSocketEvent);
}
