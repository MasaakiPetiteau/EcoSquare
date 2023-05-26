// BOUTON
const int bouton = 2;
int valeur_bouton;

// POMPE
const int relais = 3;

// CAPTEURS TEMPERATURE
const int B = 4275;
const int R0 = 100000;
const int capt_temp1 = A0;
const int capt_temp2 = A1;

// CAPTEUR HUMIDITE
int capt_humi = A2;
int humi = 0;

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

  // CAPTEURS TEMPERATURE
  int a = analogRead(capt_temp1);
  float R = 1023.0/a-1.0; R = R0*R;
  float temp1 = 1.0/(log(R/R0)/B+1/298.15)-273.15; // CAN pour le capt_temp1
  
  int a2 = analogRead(capt_temp2);
  float R2 = 1023.0/a-1.0; R2 = R0*R2;
  float temp2 = 1.0/(log(R2/R0)/B+1/298.15)-273.15; // CAN pour le capt_temp2

  // CAPTEUR HUMIDITE
  humi = analogRead(capt_humi);
  
  // MONITEUR SERIE
  String message = "Temp1 = " + String(temp1) + ", Temp2 = " + String(temp2) + ", Humi = " + String(humi);
  Serial.println(message);

  // AUTOMATISATION
  // Dans cette partie du code, on va utiliser les données des différents capteurs pour commander la pompe par l'intermédiaire du relais.
}
