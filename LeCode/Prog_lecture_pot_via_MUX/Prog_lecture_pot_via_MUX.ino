//COPPIN Léna PeiP2 G4
//Programme permettant d'envoyer sur le moniteur série les valeurs de potentiomètres de 100kOhms via un CD74HC4067


// Variables
const byte PIN_EN = 2;
const byte PIN_S0 = 3;
const byte PIN_S1 = 4;
const byte PIN_S2 = 5;
const byte PIN_S3 = 6;
const byte PIN_SIG = A0;
 
void setup(){
  
  // Adresses en sorties et à LOW
  pinMode(PIN_S0, OUTPUT);
  pinMode(PIN_S1, OUTPUT); 
  pinMode(PIN_S2, OUTPUT); 
  pinMode(PIN_S3, OUTPUT); 
  pinMode(PIN_EN, OUTPUT);
  digitalWrite(PIN_S0, LOW);
  digitalWrite(PIN_S1, LOW);
  digitalWrite(PIN_S2, LOW);
  digitalWrite(PIN_S3, LOW);
  digitalWrite(PIN_EN, LOW);
 
  Serial.begin(9600);
}
 
void loop(){
 
  // Envoi des valeurs sur le port série
  for(byte i = 0; i < 16; i++){
    Serial.print("Voie ");
    Serial.print(i);
    Serial.print(" : ");
    Serial.println(readAnalogMux(i));
  }
  
  // Delai d'affichage
  delay(1000);
}
 
//Fonction de lecture
int readAnalogMux(byte channel) {
  
  // Selection de la voie
  digitalWrite(PIN_S0, bitRead(channel, 0));
  digitalWrite(PIN_S1, bitRead(channel, 1));
  digitalWrite(PIN_S2, bitRead(channel, 2));
  digitalWrite(PIN_S3, bitRead(channel, 3));
 
  // Lecture de la valeur
  return analogRead(PIN_SIG);
}
