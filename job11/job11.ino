//définition des broches de la LED et du bouton
const int LED = 9;
const int button = 2;

//variables pour suivre l'état du bouton
int buttonState = 0; //état actuel du bouton
int lastButtonState = 0; //état précédent du bouton

//variables pour compter les appuis sur le bouton
int buttonCount = 0; //nombre d'appuis sur le bouton
unsigned long lastDebounceTime = 0; //dernier temps de rebondissement du bouton
unsigned long debounceDelay = 50; //délai de rebondissement pour éviter les faux déclenchements

//variables pour le clignotement de la LED
bool ledState = false; //état actuel de la LED
unsigned long lastBlinkTime = 0; //dernier temps d'inversion de l'état de la LED
unsigned long blinkInterval = 500; //intervalle entre deux inversions de l'état de la LED

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  Serial.begin(9600); //facultatif, pour débuguer
}

void loop() {
  //lecture de l'état du bouton
  int reading = digitalRead(button);

  //détection d'un changement d'état
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  //vérification du délai de rebondissement
  if ((millis() - lastDebounceTime) > debounceDelay) {
    //mise à jour de l'état du bouton
    if (reading != buttonState) {
      buttonState = reading;

      //détection d'un appui sur le bouton
      if (buttonState == LOW) {
        buttonCount++;

        //action en fonction du nombre d'appuis sur le bouton
        switch (buttonCount) {
          case 1:
            digitalWrite(LED, HIGH); //allumage de la LED
            break;
          case 2:
            //aucune action, la LED reste allumée
            break;
          case 3:
            //clignotement de la LED
            ledState = !ledState;
            digitalWrite(LED, ledState);
            lastBlinkTime = millis();
            break;
        }
      }
    }
  }

  //détection d'un appui prolongé sur le bouton
  if (buttonState == LOW && (millis() - lastDebounceTime) > 1000) {
    digitalWrite(LED, LOW); //extinction de la LED
    buttonCount = 0; //réinitialisation du compteur d'appuis sur le bouton
  }

  //mise à jour de l'état précédent du bouton
  lastButtonState = reading;

  //clignotement de la LED si nécessaire
  if (ledState && (millis() - lastBlinkTime) > blinkInterval) {
    ledState = !ledState;
    digitalWrite(LED, ledState);
    lastBlinkTime = millis();
  }
}
