// définition des broches des LED
int led1 = 8;
int led2 = 9;

void setup() {
  // initialisation des broches des LED en mode sortie
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  // initialise la seed du générateur de nombres aléatoires
  randomSeed(analogRead(0));
}

void loop() {
  // allume la première LED pendant un temps aléatoire
  digitalWrite(led1, HIGH);
  delay(random(100, 1000)); // attend entre 100 et 1000 millisecondes
  digitalWrite(led1, LOW);

  // allume la deuxième LED pendant un temps aléatoire
  digitalWrite(led2, HIGH);
  delay(random(100, 1000)); // attend entre 100 et 1000 millisecondes
  digitalWrite(led2, LOW);
}
