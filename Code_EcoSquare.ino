// TEMPERATURE :
#include <math.h>
const int B = 4275;               // B value of the thermistor
const int R0 = 100000;            // R0 = 100k
const int pinTempSensor = A0;     // Grove - Temperature Sensor connect to A0
#if defined(ARDUINO_ARCH_AVR)
#define debug  Serial
#elif defined(ARDUINO_ARCH_SAMD) ||  defined(ARDUINO_ARCH_SAM)
#define debug  SerialUSB
#else
#define debug  Serial
#endif

// HUMIDITE :
int sensorPin = A1;
int humidite = 0;

// POMPE :
const int bouton = 3; // le bouton est connecté à la broche 3 de la carte Adruino
const int relais_pompe = 4; // // le relais est connecté à la broche 4 de la carte Adruino
int etatBouton;

void setup()
{
    Serial.begin(20000);
    pinMode(bouton, INPUT); // le bouton est une entrée
    pinMode(relais_pompe, OUTPUT);

    
}

void loop()
{
    // TEMPERATURE :
    int a = analogRead(pinTempSensor);
    float R = 1023.0/a-1.0;
    R = R0*R;
    float temperature = 1.0/(log(R/R0)/B+1/298.15)-273.15+12.85; // convert to temperature via datasheet // ++ correction (+12.85°C)
    Serial.print("temperature = ");
    Serial.println(temperature);
    delay(100);

    // HUMIDITE :
    humidite = analogRead(sensorPin);
    Serial.print("Moisture = " );
    Serial.println(humidite);
    delay(1000);

    // POMPE :
    etatBouton = digitalRead(bouton);
      if (etatBouton == 0) // On appuie sur le bouton poussoir 
      {
        digitalWrite(relais_pompe, HIGH); // la pompe à eau remplit la bouteille
        }
      else // On relache le bouton poussoir 
      {
        digitalWrite(relais_pompe, LOW); // la pompe à eau s'arrête
      }


}
