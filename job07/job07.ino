// définition des broches des LED
int led1 = 8;
int led2 = 9;

void setup() {
  // initialisation des broches des LED en mode sortie
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  // allume la première LED et éteint la deuxième
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW);
  delay(500); // attend 500 millisecondes

  // éteint la première LED et allume la deuxième
  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
  delay(500); // attend 500 millisecondes
}
