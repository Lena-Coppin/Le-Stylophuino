//COPPIN Léna PeiP2 G4
//Programme V2 permettant de produire une note avec une fréquence choisie (avec un buzzer) 
//et de l'altérée lors d'un changement de résistance et donc de tension
//Il doit afficher la tension envoyée au buzzer et le nom ainsi que la fréquence de la note jouée 

//Variables
const int buzzer  = 5;
const int pot = 0;
int bit_value = 0.0;
float real_tension = 0.0;


void setup() {
  Serial.begin(9600);
  pinMode(buzzer,OUTPUT);
  Serial.println("Initialisation du système");
}

void loop() {
  bit_value = analogRead(pot);
 
  real_tension = bit_value / 204.6;
  Serial.print(real_tension);
  Serial.print("  ");

if(real_tension < 0.2){
  noTone(buzzer);
  Serial.println("pas de son");
}
 if((real_tension >= 0.2) && (real_tension < 1)){
  tone(buzzer, 440);
  Serial.println("La 3: 440Hz");
  }
if((real_tension >=1) && (real_tension < 2)){
  tone(buzzer, 445);
  Serial.println("445Hz");
  }
if((real_tension >= 2) && (real_tension < 3)){
  tone(buzzer, 450);
  Serial.println("450Hz");
  }
if((real_tension >= 3) && (real_tension < 4)){
  tone(buzzer, 455);
  Serial.println("455Hz");
  }
if((real_tension >= 4) && (real_tension <= 5)){
  tone(buzzer, 466);
  Serial.println("La#3: 466Hz");
  }   
}
