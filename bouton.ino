const int bouton = 2;
int valeur_bouton;

void setup() {
  pinMode(bouton, INPUT);
  Serial.begin(9600);

}

void loop() {
  valeur_bouton = digitalRead(bouton);
  if (valeur_bouton == 0){ Serial.println("Bouton pressé");}
  else {Serial.println("Bouton relaché");}
}
