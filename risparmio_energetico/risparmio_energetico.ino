#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 2     // Digita*l pin connected to the DHT sensor 
// Feather HUZZAH ESP8266 note: use pins 3, 4, 5, 12, 13 or 14 --
// Pin 15 can work but DHT must be disconnected during program upload.

// Uncomment the type of sensor in
// use:
#define DHTTYPE    DHT11     // DHT 11
//#define DHTTYPE    DHT22     // DHT 22 (AM2302)
//#define DHTTYPE    DHT21     // DHT 21 (AM2301)

// See guide for details on sensor wiring and usage:
//   https://learn.adafruit.com/dht/overview

DHT_Unified dht(DHTPIN, DHTTYPE);

uint32_t delayMS;

int buzzer=5;//imposta il pin IO digitale del BUZZER

int fotoresistenza_Pin = A1;     // il centro del partitore lo colleghiamo al pin 0
int fotoresistenza_lettura;     // il valore che conterrà la lettura
int ledPin = 3;      // select the pin for the LED
int degree;
int condizionatore = 7;
int luce = 8;


void setup() {
  Serial.begin(9600);
  // Initialize device.
  dht.begin();
  Serial.println(F("DHTxx Unified Sensor Example"));
  // Print temperature sensor details.
  sensor_t sensor;
  dht.temperature().getSensor(&sensor);
  Serial.println(F("------------------------------------"));
  Serial.println(F("Temperature Sensor"));
  Serial.print  (F("Sensor Type: ")); Serial.println(sensor.name);
  Serial.print  (F("Driver Ver:  ")); Serial.println(sensor.version);
  Serial.print  (F("Unique ID:   ")); Serial.println(sensor.sensor_id);
  Serial.print  (F("Max Value:   ")); Serial.print(sensor.max_value); Serial.println(F("°C"));
  Serial.print  (F("Min Value:   ")); Serial.print(sensor.min_value); Serial.println(F("°C"));
  Serial.print  (F("Resolution:  ")); Serial.print(sensor.resolution); Serial.println(F("°C"));
  Serial.println(F("------------------------------------"));
  // Print humidity sensor details.
  dht.humidity().getSensor(&sensor);
  Serial.println(F("Humidity Sensor"));
  Serial.print  (F("Sensor Type: ")); Serial.println(sensor.name);
  Serial.print  (F("Driver Ver:  ")); Serial.println(sensor.version);
  Serial.print  (F("Unique ID:   ")); Serial.println(sensor.sensor_id);
  Serial.print  (F("Max Value:   ")); Serial.print(sensor.max_value); Serial.println(F("%"));
  Serial.print  (F("Min Value:   ")); Serial.print(sensor.min_value); Serial.println(F("%"));
  Serial.print  (F("Resolution:  ")); Serial.print(sensor.resolution); Serial.println(F("%"));
  Serial.println(F("------------------------------------"));
  // Set delay between sensor readings based on sensor details.
  delayMS = sensor.min_delay / 1000;
  //imposta il pin IO digitale come OUTPUT
  pinMode(buzzer,OUTPUT);
  // Inizializzo la seriale
  pinMode(ledPin, OUTPUT);
  pinMode(fotoresistenza_Pin, INPUT);
  pinMode(buzzer, INPUT);
  pinMode(luce, OUTPUT);
  pinMode(condizionatore, OUTPUT);
}

void loop() {
  fotoresistenza_lettura = analogRead(fotoresistenza_Pin);  // lettura grezza dall'adc

Serial.print("Valore letto = ");
Serial.print(fotoresistenza_lettura);     //stampiamo il valore
int degreeMap = map(fotoresistenza_lettura, 0, 1023, 0, 150);

degree = 180 - degreeMap;
Serial.println(degree);
// Mettiamo delle soglie di giudizio
analogWrite(ledPin, degree);   
if (degree<40){
    digitalWrite(luce, HIGH);
}else{
    digitalWrite(luce, LOW);
}
  // Delay between measurements.
  delay(delayMS);
  // Get temperature event and print its value.
  sensors_event_t event;
  dht.temperature().getEvent(&event);
  Serial.println(event.temperature);

  if (isnan(event.temperature)) {
    Serial.println(F("Error reading temperature!"));
  }
  else if (event.temperature>30){
      digitalWrite(condizionatore, HIGH);        
  }
  else {
          digitalWrite(condizionatore, LOW);
  }
}
