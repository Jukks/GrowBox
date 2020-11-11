#include <Arduino.h>
#include <string.h>

// Requires OneWire 2.3.5 for temperature sensor
#include <OneWire.h>


// PIN FOR LIGHTS RELAY
int lightsPin = 2;
// PIN FOR WATER PUMP RELAY
int waterPumpPin = 3;
// PIN FOR SOIL MOISTURE SENSOR
int soilMoisturePin = A0;

// PIN FOR ONEWIRE TEMPERATURE SENSOR
// REQUIRES 4.7kOhm RESISTOR BETWEEN PIN AND 5V
OneWire tempSensor(4); // USE DIGITAL 4

bool lightsOn;
bool waterPumpOn;

void setup() {
  pinMode(lightsPin, OUTPUT);
  pinMode(waterPumpPin, OUTPUT);

  lightsOn = false;
  waterPumpOn = false;

  Serial.begin(9600);
}

void loop() {
  // COMMUNICATING WITH HOST MACHINE VIA SERIAL
  // USB BY DEFAULT

  /* LIST OF COMMANDS:
  lightsOn - Turn on lights
  lightsOff - Turn off lights
  waterOn - Turn on water pump
  waterOff - Turn off water pump

  readSoilMoisture - send soil moisture
  readSoilTemp - send soil temperature

  */

  // READ COMMAND FROM SERIAL PORT
  if(Serial.available() > 0){
    String s = Serial.readString();
    
    if(s=="lightsOn"){
      lightsOn = true;
      Serial.println("Lights on");
    }
    
    else if (s=="lightsOff"){
      lightsOn = false;
      Serial.println("Lights off");
    }
    
    else if(s=="readmoisture"){
    
    }
    else{
      Serial.println("error");
    }
  }

  // ACTIVATE RELAYS
  if (lightsOn){
    digitalWrite(lightsPin, HIGH);
  }
  else{
    digitalWrite(lightsPin, LOW);
  }

  if (waterPumpOn){
    digitalWrite(waterPumpPin, HIGH);
  }
  else{
    digitalWrite(waterPumpPin, LOW);
  }

}