// Code generated by Arduino IoT Cloud, DO NOT EDIT.

#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>

const char SSID[]     = SECRET_SSID;    // Network SSID (name)
const char PASS[]     = SECRET_PASS;    // Network password (use for WPA, or use as key for WEP)


CloudAcceleration accx;
CloudAcceleration accy;
CloudAcceleration accz;
CloudAcceleration counter_1;
CloudAcceleration counter_2;
CloudAcceleration counter_3;
CloudAcceleration counter_4;

void initProperties(){

  ArduinoCloud.addProperty(accx, READ, ON_CHANGE, NULL);
  ArduinoCloud.addProperty(accy, READ, ON_CHANGE, NULL);
  ArduinoCloud.addProperty(accz, READ, ON_CHANGE, NULL);
  ArduinoCloud.addProperty(counter_1, READ, ON_CHANGE, NULL);
  ArduinoCloud.addProperty(counter_2, READ, ON_CHANGE, NULL);
  ArduinoCloud.addProperty(counter_3, READ, ON_CHANGE, NULL);
  ArduinoCloud.addProperty(counter_4, READ, ON_CHANGE, NULL);

}

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);
