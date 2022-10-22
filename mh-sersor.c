const int IN_A0 = A1;
const int IN_D0 = 3;

void setup() {
  Serial.begin(9600);
  pinMode (IN_A0, INPUT);
  pinMode (IN_D0, INPUT);
 
}

int value_A0;
bool value_D0;

void loop() {
  value_A0 = analogRead(IN_A0);
  value_D0 = digitalRead(IN_D0);
  
  Serial.print(" Analogue = "); 
  Serial.print(value_A0);
  Serial.print("\t Digital ="); 
  Serial.println(value_D0);
  
  delay(100);
}