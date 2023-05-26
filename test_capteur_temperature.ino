const int B = 4275; // Coefficient bêta du thermistance
const int R0 = 100000; // Valeur de résistance à une température de référence
const int capt_temp1 = A0;
const int capt_temp2 = A1;

void setup() {
  Serial.begin(9600); //Fréquence d'actualisation
}

void loop() {
  int a = analogRead(capt_temp1);
  float R = 1023.0/a-1.0; R = R0*R;
  float temp1 = 1.0/(log(R/R0)/B+1/298.15)-273.15; // CAN pour le capt_temp1
  
  int a2 = analogRead(capt_temp2);
  float R2 = 1023.0/a-1.0; R2 = R0*R2;
  float temp2 = 1.0/(log(R2/R0)/B+1/298.15)-273.15; // CAN pour le capt_temp2
}
