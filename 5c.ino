 float q=30;
 float l=5;
 float V;
 float M;
 float x=-0.1;
  
void setup() {
Serial.begin(9600);
  Serial.print("X: ");Serial.print("\t");
  Serial.print("V: ");Serial.print("\t");
  Serial.println("M: ");
}

void loop() {
  
while(x<4.9)
  {
  x=x+0.1;
  V=0.5*q*l-q*x;
  M=0.5*q*l*x-0.5*q*(x*x);
  Serial.print(x);Serial.print("\t");
  Serial.print(V);Serial.print("\t");
  Serial.println(M);
  }
}