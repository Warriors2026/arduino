#include <DHT.h>

// Définition du type de capteur
#define DHTTYPE DHT11

// Broche où est connecté le DHT11
#define DHTPIN 2

// Création de l'objet DHT
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);     // Démarre la communication série
  dht.begin();            // Initialise le capteur DHT
  Serial.println("Lecture du capteur DHT11...");
}

void loop() {
  // Attendre 2 secondes entre chaque lecture
  delay(2000);

  // Lire l'humidité
  float humidite = dht.readHumidity();

  // Lire la température en degrés Celsius
  float temperature = dht.readTemperature();

  // Vérifier si la lecture a échoué
  if (isnan(humidite) || isnan(temperature)) {
    Serial.println("Erreur de lecture du capteur !");
    return;
  }

  // Afficher les résultats dans le moniteur série
  Serial.print("Humidité : ");
  Serial.print(humidite);
  Serial.print(" %  |  ");

  Serial.print("Température : ");
  Serial.print(temperature);
  Serial.println(" °C");
}
