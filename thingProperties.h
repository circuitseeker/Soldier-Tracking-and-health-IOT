// Code generated by Arduino IoT Cloud, DO NOT EDIT.

#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>


const char DEVICE_LOGIN_NAME[]  = "80b5ac16-17aa-4d03-8d2a-a7a1dc7b8826";


const char SSID[]               = SECRET_SSID;    // Network SSID (name)
const char PASS[]               = SECRET_OPTIONAL_PASS;    // Network password (use for WPA, or use as key for WEP)
const char DEVICE_KEY[]  = SECRET_DEVICE_KEY;    // Secret device password

void onPulseChange();
void onHumidChange();
void onTempChange();

CloudHeartRate pulse;
CloudRelativeHumidity humid;
CloudTemperature temp;

void initProperties(){

  ArduinoCloud.setBoardId(DEVICE_LOGIN_NAME);
  ArduinoCloud.setSecretDeviceKey(DEVICE_KEY);
  ArduinoCloud.addProperty(pulse, READWRITE, ON_CHANGE, onPulseChange);
  ArduinoCloud.addProperty(humid, READWRITE, ON_CHANGE, onHumidChange);
  ArduinoCloud.addProperty(temp, READWRITE, ON_CHANGE, onTempChange);

}

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);
