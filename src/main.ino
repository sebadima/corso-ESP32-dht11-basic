#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>

#define DHTPIN  13    // Pin #13 dell ESP32
#define DHTTYPE DHT11 // DHT 11
DHT dht(DHTPIN, DHTTYPE);

float t;
float h;


void setup(){
  Serial.begin(115200);
  dht.begin();
}

void loop(){  
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
      Serial.print("Umidità = ");
      Serial.println(h);
    }

    delay(1000);
}
