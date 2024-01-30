//Globale variabelen
#include "AudioZero.h";
#include "SPI.h";
#include "SD.h";
int analogSelect = A5;
int analogValue = A6;
int selector;
int draaiert;

// Variabelen voor Berekening 1: Afgeknotte kegel
int diametergrond1; //Onderkant van de kegel
int diameterboven1; //Bovenzijde kegel
int hoogte1; //Hoogte van afgeknotte kegel
float hoogte2(float radius2, int hoogte1, float radius1){
	return (radius2*hoogte1)/(radius1-radius2);
	}
float Berekening1(float radius1, float radius2, int hoogte1, float hoogte2){
  	float AntwoordTussen1 = (1.0/3.0)*M_PI*(radius1*radius1)*(hoogte1+hoogte2);
 	float AntwoordTussen2 = (1.0/3.0)*M_PI*(radius2*radius2)*(hoogte2);
  	return AntwoordTussen1 - AntwoordTussen2;
	}
float Antwoord1;
//Variabelen voor Berekening 2
int diametercilinder2;
float volume2 = 1000000;//mm3
float hoogtecilinder2(float volume2, int diametercilinder2){
	float h = volume2/(M_PI*(1.0/4.0)*(diametercilinder2*diametercilinder2));
	return h;
	}
float oppervlaktenblik2(int diametercilinder2, float hoogtecilinder2){
	float O = 2.0*M_PI*((0.5*diametercilinder2)*(0.5*diametercilinder2))+2.0*M_PI*(0.5*diametercilinder2)*hoogtecilinder2;  
      return O;
	}

//////
void setup() {
  Serial.begin(9600);
  while (!Serial){
    ;
  }
  Serial.println("Welkom");
  Serial.print("Voorbereiden SD kaart...");

  if (!SD.begin()) {

    Serial.println(" Mislukt");

    while(true);

  }

  Serial.println("Gereed.");
  AudioZero.begin(88200);  

  File Opstart = SD.open("Opstart.wav");
   if (!Opstart) {
    Serial.println("error openen opstart jingle :(");
  }
  Serial.print("Opstarten");
  // until the file is not finished
  AudioZero.play(Opstart);
}

void loop() {
//MAIN MENU
mainmenu:
File Opstart = SD.open("1.wav");
AudioZero.play(Opstart);
  delay(2000);
  Serial.println("Selecteer berekening");
  selector = analogRead(analogSelect);
  draaiert = analogRead(analogValue)/204.6;
  Serial.println(draaiert + 1);
//BEREKENING 1
  if(selector>750 && draaiert==0){
    Serial.println("Bevestiging gebruik berekening 1.");
    Serial.println("Bereken het volume van een afgeknotte cirkel");
	  
berekening1stap1:
    delay(2000);
    Serial.println("Voer waarde voor de diameter van het grondvlak in (cm)");
    
    do {
      diametergrond1 = map(analogRead(analogValue),0,1023,0,50);
      Serial.println(diametergrond1);
      selector = analogRead(analogSelect);
      delay(2000);
      }  
    while (selector < 750 && selector > 250);
    if(selector < 250){
      goto mainmenu;
    }
    Serial.print("Uw gekozen waarde is:");Serial.println(diametergrond1);
	  
berekening1stap2:
    delay(2000);
    Serial.println("Voer waarde voor de diameter van het bovenvlak in (cm)");
    
    do {
      diameterboven1 = map(analogRead(analogValue),0,1023,0,25);
      Serial.println(diameterboven1);
      selector = analogRead(analogSelect);
      delay(2000);
      }  
    while (selector < 750 && selector > 250);
    if(selector < 250){
      goto berekening1stap1;
    }
    Serial.print("Uw gekozen waarde is:");Serial.println(diameterboven1);
    delay(2000);
	  
    Serial.println("Voer waarde voor de hoogte van de afgeknotte kegel in (cm)");
    
    do {
      hoogte1 = map(analogRead(analogValue),0,1023,1,100);
      Serial.println(hoogte1);
      selector = analogRead(analogSelect);
      delay(2000);
      }  
    while (selector < 750 && selector > 250);
    if(selector < 250){
      goto berekening1stap2;
    }
    Serial.print("Uw gekozen waarde is:");Serial.println(hoogte1);
    delay(2000);
    float radius1 = diametergrond1/2.0;
	float radius2= diameterboven1/2.0;
    Antwoord1 = Berekening1(radius1,radius2,hoogte1,hoogte2(radius2, hoogte1, radius1));
    Serial.print("Het volume van uw gekozen kegel is:"); Serial.print(Antwoord1);Serial.println("cm3");
    delay(2000);
  }
//BEREKENING 2
  if(selector>750 && draaiert==1){
    Serial.println("Bevestiging gebruik berekening 2");
    Serial.println("Optimalisering van plaatmateriaal");
	  
berekening2stap1:
    delay(2000);
    Serial.println("Voer waarde voor de diameter de cilinder in (mm)");
    do {
      diametercilinder2 = map(analogRead(analogValue),0,1023,75,125);
      Serial.println(diametercilinder2);
      selector = analogRead(analogSelect);
      delay(2000);
      }  
    while (selector < 750 && selector > 250);
    if(selector < 250){
      goto mainmenu;
    }
    Serial.print("Uw gekozen waarde is:");Serial.println(diametercilinder2);
	  
berekening2stap2:
    delay(2000);
    Serial.print("Bij een diameter van "); Serial.print(diametercilinder2); Serial.print("mm en een volume van "); 
    Serial.print(volume2/1000000); Serial.print(" liter, is de hoogte van de cilinder "); 
    Serial.print(hoogtecilinder2(volume2, diametercilinder2)); Serial.println("mm.");
    if(selector < 250){
      goto berekening1stap1;
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
}
