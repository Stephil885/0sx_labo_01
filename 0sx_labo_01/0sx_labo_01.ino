// Déclaration des constantes et variables globales
const int BROCHE_LED = 13;               // Broche de la LED intégrée
const int TEMPS_CLIGNOTEMENT = 250;      // Temps d'attente pour le clignotement
const int TEMPS_PAUSE = 1000;            // Temps d'attente entre les séquences
const int RESOLUTION_PWM = 255;         // Résolution PWM (0-255)
const int DUREE_TOTALE_PWM = 2048;      // Durée totale pour la variation PWM
const int FREQUENCE_CLIGNOTEMENT = 6;//ceil(9/2)+1 Fréquence calculée
const int TEMPS_ATTENTE_LED = 2000;     // Délai d'attente pour maintenir la LED allumée

void initialiserSysteme() {
  Serial.begin(9600);             // Initialisation de la communication série
  pinMode(BROCHE_LED, OUTPUT);    // Configuration de la broche LED comme sortie
  Serial.println("Début du programme - 2403493");
}

void allumerLED() {
  Serial.println("Allume - 2403493");
  digitalWrite(BROCHE_LED, HIGH);
  delay(TEMPS_ATTENTE_LED);        // Maintient la LED allumée pendant 2 secondes
  digitalWrite(BROCHE_LED, LOW);
  delay(TEMPS_PAUSE);
}

void clignoterLED() {
  Serial.println("Clignotement - 2403493");
  for (int i = 0; i < FREQUENCE_CLIGNOTEMENT; i++) {
    digitalWrite(BROCHE_LED, HIGH);
    delay(TEMPS_CLIGNOTEMENT);     // Temps d'attente pour allumer la LED
    digitalWrite(BROCHE_LED, LOW);
    delay(TEMPS_CLIGNOTEMENT);     // Temps d'attente pour éteindre la LED
  }
  delay(TEMPS_PAUSE);             // Pause avant la prochaine séquence
}

void varierIntensiteLED() {
  Serial.println("Variation - 2403493");
  int delai = DUREE_TOTALE_PWM / RESOLUTION_PWM; // Calcul du délai entre chaque étape
  for (int i = RESOLUTION_PWM; i >= 0; i--) {
    analogWrite(BROCHE_LED, i);  // Applique une intensité croissante à la LED
    delay(delai);
  }
}

void eteindreLED() {
  Serial.println("Eteint - 2403493");
  digitalWrite(BROCHE_LED, LOW);
  delay(TEMPS_ATTENTE_LED);
}

void afficherCompteur() {
  static int compteur = 0;        // Conserve la valeur entre les appels
  compteur++;
  Serial.print("Tour: ");
  Serial.println(compteur);
}

void setup() {
  initialiserSysteme();
}

void loop() {
  afficherCompteur();             // Affiche le numéro du cycle actuel
  allumerLED();                    // Allume la LED
  clignoterLED();                  // Fait clignoter la LED
  varierIntensiteLED();            // Fait varier l'intensité de la LED
  eteindreLED();                   // Éteint la LED
}
