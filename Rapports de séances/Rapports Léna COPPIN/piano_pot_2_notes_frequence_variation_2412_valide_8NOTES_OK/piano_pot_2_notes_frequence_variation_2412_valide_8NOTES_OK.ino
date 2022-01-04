//COPPIN Léna G4 PeiP2
//Programme permettant d'émettre un son avec un buzzer lors de l'appui d'une "touche" (appelée "bouton" ici) 
//Un potentiomètre lit et module la tension analogique envoyée aux I/O et en focntion de celle-ci on module la fréquence sortant du buzzer  = effet "pitchbend"
//Uniquement sur les touches naturelles


//Déclaration des pins 
int but1 = 3;    //DO3
int but3 = 5;    //RE3
int but5 = 7;    //MI3
int but6 = 8;    //FA3
int but8 = 10;   //SOL3
int but10 = 12;  //LA3
int but12 = 4;   //SI3
int but13 = 6;   //DO4

int buzzer = 2;


//Initialisation des variables
const int pot = 0;
int bit_value = 0.0; //tension numérique
float real_tension = 0.0; //tension analogique

int f = 0; //fréquence 

void setup()
{
  //Déclarations des pins des "boutons" en INPUT
  pinMode(but1, INPUT);
  pinMode(but3, INPUT);
  pinMode(but5, INPUT);
  pinMode(but6, INPUT);
  pinMode(but8, INPUT);
  pinMode(but10, INPUT);
  pinMode(but12, INPUT);
  pinMode(but13, INPUT);

  //Déclarations des pins du buzzer en OUTPUT
  pinMode(buzzer, OUTPUT);

  //Communication voie série
  Serial.begin(9600);
}


void loop()
{
  //Lecture des valeurs des "boutons" (0 ou 1)
  int b1 = digitalRead(but1);
  int b3 = digitalRead(but3);
  int b5 = digitalRead(but5);
  int b6 = digitalRead(but6);
  int b8 = digitalRead(but8);
  int b10 = digitalRead(but10);
  int b12 = digitalRead(but12);
  int b13 = digitalRead(but13);

  //Lecture de la tension et affichage
  bit_value = analogRead(pot);
  real_tension = bit_value / 204.6;
  //Serial.print(real_tension);
  //Serial.print("  ");

  
//b1=1
  if( b1 == 1 ) {
    int f = 262;
  
    if(real_tension < 0.35){
      tone(buzzer, f);
      Serial.println("DO3 : 262 Hz");
      }
  
    if((real_tension >= 0.35) && (real_tension < 0.8)){
      tone(buzzer, f+4);
      Serial.println("Modulation : 266 Hz");
      }
  
    if((real_tension >= 0.8) && (real_tension < 3)){
      tone(buzzer, f+7);
      Serial.println("Modulation : 269 Hz");
      }
        
    if((real_tension >= 3) && (real_tension < 4.8)){
      tone(buzzer, f+11);
      Serial.println("Modulation : 273 Hz");
      }
  
    if((real_tension >= 4.8) && (real_tension <= 5)){
      tone(buzzer, f+15);
      Serial.println("DO#3 : 277 Hz");
      } 
    }





//b1=0
  if (b1==0) {
    
    //b3=0
    if (b3 == 0){
      
      //b5=0
      if (b5 == 0){
  
        //b6=0
        if (b6 == 0){
          
          //b8=0
          if (b8 == 0){
            
            //b10=0
            if (b10 == 0){
              
              //b12=0
              if (b12 == 0){
                
                //b13=0
                if (b13 == 0){
                  noTone(buzzer);
              }
                 //b13=1
                 if (b13 == 1){
                  
                  int f = 523;
                  
                  if(real_tension < 0.35){
                    tone(buzzer, f);
                    Serial.println("DO4 : 523 Hz");
                    }
                
                  if((real_tension >= 0.35) && (real_tension < 0.8)){
                    tone(buzzer, f+8);
                    Serial.println("Modulation : 531 Hz");
                    }
                
                  if((real_tension >= 0.8) && (real_tension < 3)){
                    tone(buzzer, f+16);
                    Serial.println("Modulation : 539 Hz");
                    }
                      
                  if((real_tension >= 3) && (real_tension < 4.8)){
                    tone(buzzer, f+24);
                    Serial.println("Modulation : 547 Hz");
                    }
                
                  if((real_tension >= 4.8) && (real_tension <= 5)){
                    tone(buzzer, f+31);
                    Serial.println("DO#4 : 554 Hz");
                    } 
                  }
                }
              }
            }
          }
        }
      }
    }  
                  
              //b12=1
              if (b12 == 1){
                int f = 494;
                
                if(real_tension < 0.35){
                  tone(buzzer, f);
                  Serial.println("SI3 : 494 Hz");
                  }
              
                if((real_tension >= 0.35) && (real_tension < 0.8)){
                  tone(buzzer, f+7);
                  Serial.println("Modulation : 501 Hz");
                  }
              
                if((real_tension >= 0.8) && (real_tension < 3)){
                  tone(buzzer, f+14);
                  Serial.println("Modulation : 508 Hz");
                  }
                    
                if((real_tension >= 3) && (real_tension < 4.8)){
                  tone(buzzer, f+21);
                  Serial.println("Modulation : 515 Hz");
                  }
              
                if((real_tension >= 4.8) && (real_tension <= 5)){
                  tone(buzzer, f+29);
                  Serial.println("DO4 : 523 Hz");
                }
              }
            
  
            //b10=1
            if (b10 == 1){
              int f = 440;
            
              if(real_tension < 0.35){
                tone(buzzer, f);
                Serial.println("LA3 : 440 Hz");
                }
            
              if((real_tension >= 0.35) && (real_tension < 0.8)){
                tone(buzzer, f+6);
                Serial.println("Modulation : 446 Hz");
                }
            
              if((real_tension >= 0.8) && (real_tension < 3)){
                tone(buzzer, f+12);
                Serial.println("Modulation : 452 Hz");
                }
                  
              if((real_tension >= 3) && (real_tension < 4.8)){
                tone(buzzer, f+18);
                Serial.println("Modulation : 458 Hz");
                }
            
              if((real_tension >= 4.8) && (real_tension <= 5)){
                tone(buzzer, f+26);
                Serial.println("LA#3 : 466 Hz");
                } 
                   }

          //b8=1
          if (b8 == 1){
            int f = 392;
          
            if(real_tension < 0.35){
              tone(buzzer, f);
              Serial.println("SOL3 : 392 Hz");
              }
          
            if((real_tension >= 0.35) && (real_tension < 0.8)){
              tone(buzzer, f+6);
              Serial.println("Modulation : 398 Hz");
              }
          
            if((real_tension >= 0.8) && (real_tension < 3)){
              tone(buzzer, f+12);
              Serial.println("Modulation : 404 Hz");
              }
                
            if((real_tension >= 3) && (real_tension < 4.8)){
              tone(buzzer, f+18);
              Serial.println("Modulation : 410 Hz");
              }
          
            if((real_tension >= 4.8) && (real_tension <= 5)){
              tone(buzzer, f+23);
              Serial.println("SOL#3 : 415 Hz");
              } 
           }
  
        //b6=1
        if (b6 == 1){
          int f = 349;
        
          if(real_tension < 0.35){
            tone(buzzer, f);
            Serial.println("FA3 : 349 Hz");
            }
        
          if((real_tension >= 0.35) && (real_tension < 0.8)){
            tone(buzzer, f+5);
            Serial.println("Modulation : 354 Hz");
            }
        
          if((real_tension >= 0.8) && (real_tension < 3)){
            tone(buzzer, f+10);
            Serial.println("Modulation : 359 Hz");
            }
              
          if((real_tension >= 3) && (real_tension < 4.8)){
            tone(buzzer, f+15);
            Serial.println("Modulation : 364 Hz");
            }
        
          if((real_tension >= 4.8) && (real_tension <= 5)){
            tone(buzzer, f+21);
            Serial.println("FA#3 : 370 Hz");
            }
       } 
           
      //b5=1
      if (b5 == 1){
        int f = 330;
      
        if(real_tension < 0.35){
          tone(buzzer, f);
          Serial.println("MI3 : 330 Hz");
          }
      
        if((real_tension >= 0.35) && (real_tension < 0.8)){
          tone(buzzer, f+5);
          Serial.println("Modulation : 335 Hz");
          }
      
        if((real_tension >= 0.8) && (real_tension < 3)){
          tone(buzzer, f+10);
          Serial.println("Modulation : 340 Hz");
          }
            
        if((real_tension >= 3) && (real_tension < 4.8)){
          tone(buzzer, f+15);
          Serial.println("Modulation : 345 Hz");
          }
      
        if((real_tension >= 4.8) && (real_tension <= 5)){
          tone(buzzer, f+19);
          Serial.println("FA3 : 349 Hz");
          } 
       }
        
  //b3=1
  if ( b3 == 1 ){
    int f = 294;
  
    if(real_tension < 0.35){
      tone(buzzer, f);
      Serial.println("RE3 : 294 Hz");
      }
  
    if((real_tension >= 0.35) && (real_tension < 0.8)){
      tone(buzzer, f+4);
      Serial.println("Modulation : 298 Hz");
      }
  
    if((real_tension >= 0.8) && (real_tension < 3)){
      tone(buzzer, f+8);
      Serial.println("Modulation : 302 Hz");
      }
        
    if((real_tension >= 3) && (real_tension < 4.8)){
      tone(buzzer, f+12);
      Serial.println("Modulation : 306 Hz");
      }
  
    if((real_tension >= 4.8) && (real_tension <= 5)){
      tone(buzzer, f+17);
      Serial.println("RE#3 : 311 Hz");
      }
       }
    }
