//Globale variabelen
int analogSelect = A0;
int analogValue = A1;
int selector;
int draaiert;

// Variabelen voor Berekening 1: Afgeknotte kegel
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
//Variabelen voor Berekening 2



//////
void setup() {
  Serial.begin(9600);
  Serial.println("Welkom");
}

void loop() {
  mainmenu:
  delay(2000);
  Serial.println("Selecteer berekening");
  selector = analogRead(analogSelect);
  draaiert = analogRead(analogValue)/204.6;
  Serial.println(draaiert + 1);
  if(selector>750 && draaiert==0){
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
    while (selector < 750 && selector > 250);
    if(selector < 250){
      goto mainmenu;
    }
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
    if(selector < 250){
      goto mainmenu;
    }
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
    if(selector < 250){
      goto mainmenu;
    }
    Serial.print("Uw gekozen waarde is:");Serial.println(hoogte1);
    delay(2000);
    float radius1 = diametergrond1/2.0;
	float radius2= diameterboven1/2.0;
    Antwoord1 = Berekening1(radius1,radius2,hoogte1,hoogte2(radius2, hoogte1, radius1));
    Serial.print("Het volume van uw gekozen kegel is:"); Serial.print(Antwoord1);Serial.println("cm3");
    delay(2000);
  }
  if(selector>750 && draaiert==1){
    Serial.println("Bevestiging berekening 2");
    if(selector < 250){
      goto mainmenu;
    }
    delay(2000);
  }
  if(selector>750 && draaiert==2){
    Serial.println("Bevestiging berekening 3");
    if(selector < 250){
      goto mainmenu;
    }
    delay(2000);
  }
  if(selector>750 && draaiert==3){
    Serial.println("Bevestiging berekening 4");
    if(selector < 250){
      goto mainmenu;
    }
    delay(2000);
  }
  if(selector>750 && draaiert==4){
    Serial.println("Bevestiging berekening 5");
    if(selector < 250){
      goto mainmenu;
    }
    delay(2000);
  }
  if(selector>750 && draaiert==5){
    Serial.println("Bevestiging berekening 6");
    if(selector < 250){
      goto mainmenu;
    }
    delay(2000);
  }
}
