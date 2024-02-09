#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#define DHTPIN 13         // corrisponde al Pin #1 dell ESP8266
#define DHTTYPE    DHT11 // DHT 11

DHT dht(DHTPIN, DHTTYPE);

float t = 0.0;
float h = 0.0;

unsigned long previousMillis = 0;    // will store last time DHT was updated
const long interval = 10000;  


void setup(){

  Serial.begin(115200);
  dht.begin();

}

void loop(){  

  unsigned long currentMillis = millis();

    float newT = dht.readTemperature();
    if (isnan(newT)) {
      Serial.println("Non riesco a leggere il sensore DHT!");
    }
    else {
      t = newT;
      Serial.print("Temperatura = ");
      Serial.println(t);
    }

    float newH = dht.readHumidity();
    if (isnan(newH)) {
      Serial.println("Non riesco a leggere il sensore DHT!");
    }
    else {
      h = newH;
      Serial.println(h);
    }

    Serial.println("");
    delay(2000);
}
