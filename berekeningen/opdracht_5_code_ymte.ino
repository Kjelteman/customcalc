const float pi = 3.14159265359;
const float g = 9.81;  // Versnelling door zwaartekracht

int beginHoogtePotPin = A0;
int vatDiameterPotPin = A1;
int uitloopDiameterPotPin = A2;

float beginHoogte;
float vatDiameter;
float uitloopDiameter;

float vatOppervlakte =0.25 * pi * vatDiameter * vatDiameter ;
float uitloopOppervlakte =0.25 * pi * uitloopDiameter * uitloopDiameter;
float waterHoogte;  // Beginhoogte van het water in het vat

float d(float t) 
{
  return 0.1;  // Constante snelheid van 0,1 eenheden per seconde
}
int leesDraaiknop(int pin, int minVal, int maxVal) 
{
  int waarde = analogRead(pin);
  return map(waarde, 0, 1023, minVal, maxVal);

}
void oplossenDifferentiaalVergelijking() 
{
  float tijd = 0.0;

  while (waterHoogte > 0.0) 
  {
    // Differentiaalvergelijking: dh/dt = -a/A * dt * sqrt(2 * g * h)
    waterHoogte = waterHoogte - (uitloopOppervlakte / vatOppervlakte) * d(tijd) * sqrt(2 * g * waterHoogte);

    // Voeg 0,1 seconde toe aan de totale tijd
    tijd += 0.1;

    // Druk de verstreken tijd, actuele waterhoogte en andere variabelen af
    Serial.print("Verstreken tijd: ");
    Serial.print(tijd, 2);  // Toon tijd met twee decimalen
    Serial.print(" seconden - Waterhoogte: ");
    Serial.print(waterHoogte, 2);  // Toon waterhoogte met twee decimalen
    Serial.print(" - Vatdiameter: ");
    Serial.print(vatDiameter, 2);  // Toon vatdiameter met twee decimalen
    Serial.print(" - Uitloopdiameter: ");
    Serial.println(uitloopDiameter, 2);  // Toon uitloopdiameter met twee decimalen
  }
}

void setup() 
{
  Serial.begin(9600);

  // Lees de waarden van de draaiknoppen en stel de variabelen in
  beginHoogte = leesDraaiknop(beginHoogtePotPin, 500, 1000);
  vatDiameter = leesDraaiknop(vatDiameterPotPin, 400, 800);
  uitloopDiameter = leesDraaiknop(uitloopDiameterPotPin, 5, 50);

  Serial.print("Beginhoogte: "); Serial.println(beginHoogte);
  Serial.print("Vatdiameter: "); Serial.println(vatDiameter);
  Serial.print("Uitloopdiameter: "); Serial.println(uitloopDiameter);

  //vatOppervlakte = 0.25 * pi * vatDiameter * vatDiameter;
  //uitloopOppervlakte = 0.25 * pi * uitloopDiameter * uitloopDiameter;

  // Lees de beginwaarden van de waterhoogte, vatdiameter en uitloopdiameter van de analoge pinnen
  waterHoogte = analogRead(beginHoogtePotPin) * (1000 / 1023.0) + 500.0;
  vatDiameter = analogRead(vatDiameterPotPin) * (800.0 / 1023.0) + 400.0;  // Aannemende minimale waarde 400 en maximale waarde 800
  uitloopDiameter = analogRead(uitloopDiameterPotPin) * (50.0 / 1023.0) + 5.0;  // Aannemende minimale waarde 5 en maximale waarde 50

  // Roep de functie op om de differentiaalvergelijking op te lossen
  oplossenDifferentiaalVergelijking();
}

void loop() {
  // Voeg hier eventuele aanvullende taken toe
}
