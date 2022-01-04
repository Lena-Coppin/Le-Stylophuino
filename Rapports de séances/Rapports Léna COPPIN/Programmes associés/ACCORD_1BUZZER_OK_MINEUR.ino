//COPPIN Léna G4 PeiP2
//Programme permettant d'émettre une suite de 3 sons (arpège d'un accord majeur) avec un buzzer lors de l'appui d'une "touche" (la fondamentale)
//Option permettant de jouer les accords mineurs en appuyant sur une touche (9a) en même temps que la note fondamentale




//Déclaration des pins 
int but1 = 3;      //DO3
int but3 = 4;      //RE3
int but5 = 5;      //MI3
int but6 = 6;      //FA3
int but8 = 7;      //SOL3
int but10 = 8;     //LA3
int but12 = 9;     //SI3
int but_min = 11;  //MINEUR

int buzzer = 2;

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
  pinMode(but_min, INPUT);

  //Déclaration pin du buzzer en OUTPUT
  pinMode(buzzer, OUTPUT);
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
  int b_min = digitalRead(but_min);

//b_min=1
if (b_min == 1){
  //b1=1
  if( b1 == 1 ) {
    tone(buzzer, 262, 200);
    delay(180);
    tone(buzzer, 311, 200);
    delay(180);
    tone(buzzer, 392, 200);
    delay(180);
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
                noTone(buzzer);
              }

              //b12=1
              if (b12 == 1){
                tone(buzzer, 494, 200);
                delay(180);
                tone(buzzer, 587, 200);
                delay(180);
                tone(buzzer, 740, 200);
                delay(180);
              }
            }
          }
        }
      }
    }
  }
  
            //b10=1
            if (b10 == 1){
              tone(buzzer, 440, 200);
              delay(180);
              tone(buzzer, 523, 200);
              delay(180);
              tone(buzzer, 639, 200);
              delay(180);
                   }
                   
          //b8=1
          if (b8 == 1){
            tone(buzzer, 392, 200);
            delay(180);
            tone(buzzer, 466, 200);
            delay(180);
            tone(buzzer, 587, 200);
            delay(180);
           }
  
        //b6=1
        if (b6 == 1){
          tone(buzzer, 349, 200);
          delay(180);
          tone(buzzer, 415, 200);
          delay(180);
          tone(buzzer, 523, 200);
          delay(180);
       } 
           
      //b5=1
      if (b5 == 1){
          tone(buzzer, 330, 200);
          delay(180);
          tone(buzzer, 392, 200);
          delay(180);
          tone(buzzer, 494, 200);
          delay(180);        
       }
        
  //b3=1
  if ( b3 == 1 ){
      tone(buzzer, 294, 200);
      delay(180);
      tone(buzzer, 349, 200);
      delay(180);
      tone(buzzer, 440, 200);
      delay(180); 
       }
   
}


//b_min=0
if (b_min == 0){
  //b1=1
  if( b1 == 1 ) {
    tone(buzzer, 262, 200);
    delay(180);
    tone(buzzer, 330, 200);
    delay(180);
    tone(buzzer, 392, 200);
    delay(180);
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
                noTone(buzzer);
              }

              //b12=1
              if (b12 == 1){
                tone(buzzer, 494, 200);
                delay(180);
                tone(buzzer, 622, 200);
                delay(180);
                tone(buzzer, 740, 200);
                delay(180);
              }
            }
          }
        }
      }
    }
  }
  
            //b10=1
            if (b10 == 1){
              tone(buzzer, 440, 200);
              delay(180);
              tone(buzzer, 554, 200);
              delay(180);
              tone(buzzer, 639, 200);
              delay(180);
                   }
                   
          //b8=1
          if (b8 == 1){
            tone(buzzer, 392, 200);
            delay(180);
            tone(buzzer, 494, 200);
            delay(180);
            tone(buzzer, 587, 200);
            delay(180);
           }
  
        //b6=1
        if (b6 == 1){
          tone(buzzer, 349, 200);
          delay(180);
          tone(buzzer, 440, 200);
          delay(180);
          tone(buzzer, 523, 200);
          delay(180);
       } 
           
      //b5=1
      if (b5 == 1){
          tone(buzzer, 330, 200);
          delay(180);
          tone(buzzer, 415, 200);
          delay(180);
          tone(buzzer, 494, 200);
          delay(180);        
       }
        
  //b3=1
  if ( b3 == 1 ){
      tone(buzzer, 294, 200);
      delay(180);
      tone(buzzer, 370, 200);
      delay(180);
      tone(buzzer, 440, 200);
      delay(180); 
       }
}
}
