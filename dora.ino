#include "arduino_secrets.h"
#include <DHT.h>

#define DHTPIN 2    // Define the pin where DHT11 is connected
#define DHTTYPE DHT11 // Define the type of DHT sensor

#define PULSE_PIN 4  // Define the pin where the pulse sensor is connected

DHT dht(DHTPIN, DHTTYPE); // Initialize DHT sensor

/* 
  The following variables 
  CloudHeartRate pulse;
  CloudRelativeHumidity humid;
  CloudTemperature temp;
*/

#include "thingProperties.h"

void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 

  dht.begin(); // Start DHT sensor
  pinMode(PULSE_PIN, INPUT); // Set pulse sensor pin as input

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
  
  // Read DHT sensor data
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Read pulse sensor data (replace this with your specific pulse sensor library)
  int pulseValue = digitalRead(PULSE_PIN);

  // Update Arduino Cloud variables
  humid = humidity;
  temp = temperature;
  pulse = pulseValue;
}

/*
  Since Temp is READ_WRITE variable, onTempChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onTempChange()  {
  // Add your code here to act upon Temp change
}

/*
  Since Humid is READ_WRITE variable, onHumidChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onHumidChange()  {
  // Add your code here to act upon Humid change
}

/*
  Since Pulse is READ_WRITE variable, onPulseChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onPulseChange()  {
  // Add your code here to act upon Pulse change
}
