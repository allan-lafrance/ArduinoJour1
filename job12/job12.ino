//définition des broches pour les LED et le potentiomètre
const int LED1 = 9;
const int LED2 = 10;
const int potPin = A0;

void setup() {
  //initialisation des broches en sortie pour les LED
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}

void loop() {
  //lecture de la position du potentiomètre
  int potValue = analogRead(potPin);

  //calcul des valeurs de luminosité pour les deux LED
  int brightness1 = potValue / 4;
  int brightness2 = 255 - brightness1;

  //mise à jour de la luminosité des LED
  analogWrite(LED1, brightness1);
  analogWrite(LED2, brightness2);
}
