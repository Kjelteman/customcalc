//SELECTIEPRINCIPE --> Hier heb ik de potentiometer zo gemaakt dat als die rechtsom gedraaid is, deze 'bevestigd'.
int analogSelect = A0;
int analogValue = A1;
int selector = 0;
int Term1;
int Term2;
int Term3;
float RS;
  
float Berekening1(int Term1,int Term2,int Term3){
  	float Antwoord1;
    Antwoord1 = (Term1*Term1)+(Term2*Term2*Term2)- Term3;
    return Antwoord1;
	}

void setup() {
  Serial.begin(9600);
  Serial.println("Lets have it");
}

void loop() {
  selector = analogRead(analogSelect);
  if(selector<250){
    Serial.println("Bevestig gebruik berekening 1.");
    delay(2000);
  }
  if(selector>750){
    Serial.println("Voer waarde voor term 3 in");
    	int selectedVal = analogRead(analogValue);
    	int a = 2;
        int b = 1;
        int c = selectedVal * 0.01;
    Serial.print("The value for Term 3 is:");
    Serial.println(c);
    delay(2000);
    selector = analogRead(analogSelect);
    if(selector<250){
    	RS = Berekening1(a, b, c);
      	Serial.print("The answer to your equation is:");
     	Serial.println(RS);
     	delay(2000);
    }
  }
}   
