int sliderselect = A0;
int draaiknop = A1;

//Hieronder de berekening functies te plaatsen, met daarbij de relevante variabelen.

// Berekening 1: Afgeknotte kegel
int diametergrond1; //Onderkant van de kegel
float radius1 = diametergrond1/2;
int diameterboven1; //Bovenzijde kegel
float radius2 = diameterboven1/2;
int hoogte1; //Hoogte van afgeknotte kegel
int hoogte2 = (-radius2*hoogte1)/(radius1-radius2); //Hoogte van topje
float Berekening1 (int radius1, int radius2, int hoogte1, int hoogte2){
  float AntwoordTussen1;
  float AntwoordTussen2;
  float AntwoordEind1;
  AntwoordTussen1 = (1/3)*PI*(hoogte1+hoogte2)*(radius1*radius1);
  AntwoordTussen2 = (1/3)*PI*(radius2*radius2)*hoogte2;
  AntwoordEind1 = AntwooordTussen1 - AntwoordTussen2;
  return AntwoordEind1;
}

//Berekening 2: Volume conserven
int Volume2 = 1000;//cm3
int diameter2;
float hoogte2 = Volume2/(PI*(1/4)*(diameter2*diameter2));

float Berekening2 (){


}



void setup() {
  Serial.begin(9600);
  Serial.println("Hello World")
}

void loop() {


}
