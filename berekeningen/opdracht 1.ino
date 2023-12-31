// Berekening 1: Afgeknotte kegel
// Dit bestand in de ardunio werkt vrijwel compleet!!!!

int diametergrond1; //Onderkant van de kegel

int diameterboven1; //Bovenzijde kegel

int hoogte1; //Hoogte van afgeknotte kegel

float hoogte2(float radius2, int hoogte1, float radius1){
  float h = (radius2*hoogte1)/(radius1-radius2);
  return h;
}
float Berekening1(float radius1, float radius2, int hoogte1, float hoogte2){
  float AntwoordTussen1;
  float AntwoordTussen2;
  float AntwoordEind1;
  AntwoordTussen1 = (1.0/3.0)*M_PI*(radius1*radius1)*(hoogte1+hoogte2);
  AntwoordTussen2 = (1.0/3.0)*M_PI*(radius2*radius2)*(hoogte2);
  AntwoordEind1 = AntwoordTussen1 - AntwoordTussen2;
  return AntwoordEind1;
}

float Antwoord1;

//Test berekening hieronder:

int analogSelect = A0;
int analogValue = A1;
int selector;

void setup() {
  Serial.begin(9600);
  Serial.println("Let's have it");
}

void loop() {
  selector = analogRead(analogSelect);
  if(selector>750){
    Serial.println("Bevestiging gebruik berekening 1.");
    Serial.println("Bereken het volume van een afgeknotte cirkel");
    delay(2000);
    Serial.println("Voer waarde voor de diameter van het grondvlak in");
    
    do {
      diametergrond1 = analogRead(analogValue)/20.46;
      Serial.println(diametergrond1);
      selector = analogRead(analogSelect);
      delay(2000);
      }  
    while (selector < 750);
    
    Serial.print("Uw gekozen waarde is:");Serial.println(diametergrond1);
    delay(2000);
    Serial.println("Voer waarde voor de diameter van het bovenvlak in");
    
    do {
      diameterboven1 = analogRead(analogValue)/40.92;
      Serial.println(diameterboven1);
      selector = analogRead(analogSelect);
      delay(2000);
      }  
    while (selector < 750);
    
    Serial.print("Uw gekozen waarde is:");Serial.println(diameterboven1);
    delay(2000);
    Serial.println("Voer waarde voor de hoogte van de afgeknotte kegel in");
    
    do {
      hoogte1 = analogRead(analogValue)/10.23;
      Serial.println(hoogte1);
      selector = analogRead(analogSelect);
      delay(2000);
      }  
    while (selector < 750);
    
    Serial.print("Uw gekozen waarde is:");Serial.println(hoogte1);
    delay(2000);
    float radius1 = diametergrond1/2.0;
	float radius2= diameterboven1/2.0;
    Antwoord1 = Berekening1(radius1,radius2,hoogte1,hoogte2(radius2, hoogte1, radius1));
    Serial.print("Het volume van uw gekozen kegel is:"); Serial.print(Antwoord1);Serial.println("cm3");
    delay(2000);
    }
}
