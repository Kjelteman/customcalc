#include <Arduino.h>
#include <math.h>

const int potPinX = A0;   // Pin waar de draaiknop voor x op is aangesloten
const int slidePin = A1;  // Pin waar de schuifknop op is aangesloten

bool calculationActive = false;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int slideValue = analogRead(slidePin);

  if (!calculationActive) {
    // Controleer de schuifwaarde om te beslissen of we naar het hoofdmenu moeten gaan
    if (slideValue >= 0 && slideValue < 250) {
      Serial.println("Terug naar hoofdmenu");
      // Reset de actieve berekening
      calculationActive = false;
      // Wacht een korte periode om te voorkomen dat het hoofdmenu te snel wordt verlaten
      delay(500);
    } else if (slideValue > 750 && slideValue <= 1000) {
      // Berekening starten wanneer de schuif naar rechts is geschoven
      Serial.println("Berekening gestart");
      calculationActive = true;
    }
  } else {
    // De berekening is actief, wacht op de resultaten
    float x = map(analogRead(potPinX), 0, 1023, 0, 500);

    // De formule: (-34 * 9.81 * sin(atan(4/x))) + 80 * 9.81) * 0.4 - (34 * 9.81 * cos(atan(4/x)))
    float result = (-34 * 9.81 * sin(atan(4 / x)) + 80 * 9.81) * 0.4 - (34 * 9.81 * cos(atan(4 / x)));

    // Controleer het resultaat en print de gewenste uitvoer
    if (result < 0) {
      Serial.println("Glijdt uit");
    } else if (result > 0) {
      Serial.println("Glijdt niet uit");
    } else {
      Serial.println("Glijdt net niet uit");
    }

    // Wacht een korte periode voordat de lus opnieuw wordt uitgevoerd
    delay(1000);

    // Reset de actieve berekening na het afdrukken van de resultaten
    calculationActive = false;
  }

  // Wacht een korte periode voordat de lus opnieuw wordt uitgevoerd
  delay(100);
}

