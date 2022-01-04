//COPPIN Léna PeiP2 G4
//Programme permettant de produire une note avec une fréquence choisie (avec un buzzer) 
//et de l'altérée lors d'un changement de résistance et donc de tension
//Il doit afficher la tension envoyée au buzzer et le nom ainsi que la fréquence de la note jouée 

//Variables
const int buzzer  = 2;
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

//  if(real_tension < 0.2){
//    digitalWrite(buzzer, LOW);
//  }
//à modifier pour couper le son du buzzer à real_tension < 0.2 
//(et non 0 car marge d'erreur de 0,2V due à des perturbations dans l'air)

  if((real_tension >= 0,2) && (real_tension < 1.5)){
  tone(buzzer, 440);
  delay(400);
  Serial.println("La4 : 440Hz");
  }

  if((real_tension >= 1.5) && (real_tension <3)){
  tone(buzzer, 453);
  delay(400);
  Serial.println("modulation");
  }
      
  if((real_tension >= 3) && (real_tension <5)){
  tone(buzzer, 466);
  delay(400);
  Serial.println("La#4 : 466Hz");
  }
    
  Serial.print("tension : ");
  Serial.println(real_tension);
}
