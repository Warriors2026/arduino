// Broche analogique du capteur
int capteurLumiere = A0;

void setup() {
  Serial.begin(9600);   // Démarrage de la communication série
  Serial.println("Lecture du capteur de lumière...");
}

void loop() {
  // Lire la valeur analogique
  int valeurLumiere = analogRead(capteurLumiere);

  // Afficher la valeur dans le moniteur série
  Serial.print("Lumière : ");
  Serial.println(valeurLumiere);

  // Attendre 1 seconde
  delay(1000);
}
