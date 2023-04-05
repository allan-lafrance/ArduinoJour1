const int LED_PIN = 9; // Broche de la LED
const int FADE_DELAY = 10; // Délai d'attente entre chaque augmentation de la luminosité
const int FADE_STEP = 5; // Augmentation de la luminosité à chaque étape

void setup() {
  pinMode(LED_PIN, OUTPUT); // Configuration de la broche de la LED en sortie
}

void loop() {
  // Augmentation progressive de la luminosité
  for (int brightness = 0; brightness <= 255; brightness += FADE_STEP) {
    analogWrite(LED_PIN, brightness); // Allumage de la LED avec la luminosité courante
    delay(FADE_DELAY); // Attente entre chaque augmentation de la luminosité
  }

  // Diminution progressive de la luminosité
  for (int brightness = 255; brightness >= 0; brightness -= FADE_STEP) {
    analogWrite(LED_PIN, brightness); // Allumage de la LED avec la luminosité courante
    delay(FADE_DELAY); // Attente entre chaque diminution de la luminosité
  }
}