// BOUTON
const int bouton = 2;
int valeur_bouton;

// POMPE
const int relais = 3;

// CAPTEUR TEMPERATURE
#include <math.h>
const int B = 4275;
const int R0 = 100000;
const int pinTempSensor = A0;


void setup() {
  pinMode(bouton, INPUT);
  pinMode(relais, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // COMMANDE DU RELAIS VIA BOUTON
  valeur_bouton = digitalRead(bouton);
  if (valeur_bouton == 0){digitalWrite(relais, LOW);}
  else {digitalWrite(relais, HIGH);}

  // CAPTEUR TEMPERATURE
  int a = analogRead(pinTempSensor);
  float R = 1023.0/a-1.0;
  R = R0*R;
  float temperature = 1.0/(log(R/R0)/B+1/298.15)-273.15;
  Serial.print("Température = ");
  Serial.println(temperature);
  delay(1000);
}
