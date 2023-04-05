const int LED_PIN[] = {2, 3, 4, 5, 6, 7, 8, 9}; // Les broches des LEDs
const int LED_COUNT = 8; // Nombre de LEDs

void setup() {
  for (int i = 0; i < LED_COUNT; i++) {
    pinMode(LED_PIN[i], OUTPUT); // Configuration des broches des LEDs en sortie
  }
}

void loop() {
  for (int i = 0; i < LED_COUNT; i++) {
    digitalWrite(LED_PIN[i], HIGH); // Allumage de la LED courante
    delay(500); // Attente de 500ms
    digitalWrite(LED_PIN[i], LOW); // Extinction de la LED courante
  }
}
