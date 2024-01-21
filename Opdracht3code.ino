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
    } else {
      // De berekening is niet actief, lees de draaiknop voor de huidige x-waarde
      float x = map(analogRead(potPinX), 0, 1023, 0, 100);
      // Print de huidige x-waarde op het scherm
      Serial.print("Huidige X-waarde: ");
      Serial.println(x);
    }
  } else {
    // De berekening is actief, wacht op de resultaten
    float x = map(analogRead(potPinX), 0, 1023, 0, 100);

    // Begrens x tot het bereik van 0 tot 100
    x = constrain(x, 0, 100);

    // Bereken de nieuwe y-waarde
    float y = (1540000 + 7000*x + sqrt(pow(154000, 2) + 971960000000*x + pow(7000, 2)*pow(x, 2) - 9768600000*pow(x, 2) + 216000*pow(22000, 2))) / 108000;

    // Print de y-waarde
    Serial.print("Y-waarde: ");
    Serial.println(y);

    // Controleer of x de waarde heeft bereikt waarop y het laagst is
    if (x == 58.05) {
      Serial.println("Y is het laagst bij x = 58.05");
    }

    // Wacht een korte periode voordat de lus opnieuw wordt uitgevoerd
    delay(1000);

    // Reset de actieve berekening na het afdrukken van de resultaten
    calculationActive = false;
  }

  // Wacht een korte periode voordat de lus opnieuw wordt uitgevoerd
  delay(100);
}
