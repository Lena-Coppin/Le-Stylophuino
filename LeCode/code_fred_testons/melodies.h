/*********************************************************************
 *          On retrouve ici des séquences de notes
 *           déjà enregistrées et donc jouables.
*********************************************************************/



/*Ces sont les 4 premières notes de la chanson
"Ching Cheng Hanji" de l'artiste Dehao Zhang.*/
void cch_short(Tone tg, Tone td, char a='\0') {
  int i = 55;
  if (a=='-') {i = i - 12;}
  else if (a=='+') {i = i + 12;}
  tg.stop();
  td.stop();
  digitalWrite(where_led_recorded, HIGH);
  tg.play(notes[i - 12], 225);
  td.play(notes[i], 225);
  delay(325);
  tg.play(notes[i-4 - 12], 225);
  td.play(notes[i-4], 225);
  delay(325);
  tg.play(notes[i-2 - 12], 225);
  td.play(notes[i-2], 225);
  delay(325);
  tg.play(notes[i - 12], 225);
  td.play(notes[i], 225);
  delay(325);
  tg.stop();
  td.stop();
  digitalWrite(where_led_recorded, LOW);
};



/*Voici l'hymne national de la Russie.*/
void urss(Tone tg, Tone td, char a='\0') {
  int i = 43;
  if (a=='-') {i = i - 12;}
  else if (a=='+') {i = i + 12;}

  int ng1 = notes[i-7 - 12];
  int ng2 = notes[i-5 - 12];
  int ng3 = notes[i-3 - 12];
  int ng4 = notes[i-2 - 12]; 
  int ng5 = notes[i - 12];
  int ng6 = notes[i+2 - 12];
  int ng7 = notes[i+4 - 12];
  int ng8 = notes[i+5 - 12];
  int ng9 = notes[i+7 - 12];
  int ng10 = notes[i+9 - 12];
  int ng11 = notes[i+10 - 12];
  
  int nd1 = notes[i - 7];      //C-
  int nd2 = notes[i - 5];      //D-
  int nd3 = notes[i - 3];      //E-
  int nd4 = notes[i - 2];      //F-
  int nd5 = notes[i];          //G
  int nd6 = notes[i + 2];      //A+
  int nd7 = notes[i + 4];      //B+
  int nd8 = notes[i + 5];      //C+
  int nd9 = notes[i + 7];      //D+
  int nd10 = notes[i + 9];     //E+
  int nd11 = notes[i + 10];    //F+
  
  int our_left_melody[106] = {
    ng5, ng8, ng5, ng6, ng7, ng3, ng3,
    ng6, ng5, ng4, ng5, ng1, ng1,
    ng2, ng2, ng3, ng4, ng4, ng5, ng6, ng7, ng8, ng9,
    ng5, ng10, ng9, ng8, ng9, ng7, ng5,
    ng8, ng7, ng6, ng7, ng3, ng3,
    ng6, ng5, ng4, ng5, ng1, ng1,
    ng8, ng7, ng6, ng5, ng7, ng8, ng9,
    ng10, ng9, ng8, ng7, ng8, ng9, ng5, ng5, ng7, ng8, ng9,
    ng8, ng7, ng6, ng5, ng6, ng7, ng3, ng3, ng5, ng6, ng7,
    ng8, ng6, ng7, ng8, ng6, ng7, ng8, ng6, ng8, ng11,
    ng11, ng10, ng9, ng8, ng9, ng10, ng8, ng8,
    ng9, ng8, ng7, ng6, ng7, ng8, ng6, ng6,
    ng8, ng7, ng6, ng5, ng1, ng5, ng6, ng7, ng8
  };

  int our_right_melody[106] = {
    nd5, nd8, nd5, nd6, nd7, nd3, nd3,
    nd6, nd5, nd4, nd5, nd1, nd1,
    nd2, nd2, nd3, nd4, nd4, nd5, nd6, nd7, nd8, nd9,
    nd5, nd10, nd9, nd8, nd9, nd7, nd5,
    nd8, nd7, nd6, nd7, nd3, nd3,
    nd6, nd5, nd4, nd5, nd1, nd1,
    nd8, nd7, nd6, nd5, nd7, nd8, nd9,
    nd10, nd9, nd8, nd7, nd8, nd9, nd5, nd5, nd7, nd8, nd9,
    nd8, nd7, nd6, nd5, nd6, nd7, nd3, nd3, nd5, nd6, nd7,
    nd8, nd6, nd7, nd8, nd6, nd7, nd8, nd6, nd8, nd11,
    nd11, nd10, nd9, nd8, nd9, nd10, nd8, nd8,
    nd9, nd8, nd7, nd6, nd7, nd8, nd6, nd6,
    nd8, nd7, nd6, nd5, nd1, nd5, nd6, nd7, nd8
  };
  
  int reladur[106] = {
    8, 4, 6, 16, 4, 8, 8,
    4, 6, 16, 4, 8, 8,
    4, 8, 8, 4, 8, 8, 4, 8, 8, 3,
    6, 4, 6, 16, 4, 8, 8,
    4, 6, 16, 4, 8, 8,
    4, 6, 16, 4, 6, 16,
    4, 6, 16, 8, 8, 8, 8,
    2, 8, 8, 8, 8, 3, 8, 8, 8, 8, 8,
    2, 8, 8, 8, 8, 3, 8, 8, 8, 8, 8,
    4, 6, 16, 4, 6, 16, 4, 8, 8, 2,
    2, 8, 8, 8, 8, 3, 8, 2,
    2, 8, 8, 8, 8, 3, 8, 2,
    4, 6, 16, 4, 4, 2, 4, 4, 1
  };

  digitalWrite(where_led_bend, LOW);
  digitalWrite(where_led_tempo, LOW);
  tg.stop();
  td.stop();
  digitalWrite(where_led_recorded, HIGH);
  for (int k = 0; k < 106; k++) {
    int duration = 2400 / reladur[k];
    tg.play(our_left_melody[k], duration);
    td.play(our_right_melody[k], duration);
    int waiting = duration * 1.30;
    delay(waiting);
    tg.stop();
    td.stop();
  }
  digitalWrite(where_led_recorded, LOW);
  choosen_set(current_set_number);
  actual_frequencies_update();
  actual_poten_speed();
};
/*Comme le dit le propriétaire du Github ayant permis 
de réaliser cette fonction urss() :
"Quality USSR Anthem by Ömer Arda Kaya for all comrades"*/
//FAIT BIEN AVANT LE CONFLIT RUSSO-UKRAINIEN !!!



/*Voici le thème de la Panthère Rose.*/
void pink_panther(Tone tg, Tone td, char a='\0') {
  write_matrix(HIGH, 'p');
  int i = 43;
  if (a=='-') {i = i - 12;}
  else if (a=='+') {i = i + 12;}

  int melody[] = {
    REST, 2, REST,4, REST,8, NOTE_DS4, 8, 
    NOTE_E4, -4, REST, 8, NOTE_FS4, 8, NOTE_G4, -4, REST,8, NOTE_DS4, 8,
    NOTE_E4, -8, NOTE_FS4, 8, NOTE_G4, -8, NOTE_C5, 8, NOTE_B4, -8, NOTE_E4, 8, NOTE_G4, -8, NOTE_B4, 8,   
    NOTE_AS4, 2, NOTE_A4, -16, NOTE_G4, -16, NOTE_E4, -16, NOTE_D4, -16, 
    NOTE_E4, 2, REST, 4, REST, 8, NOTE_DS4, 4,
    NOTE_E4, -4, REST, 8, NOTE_FS4, 8, NOTE_G4, -4, REST, 8, NOTE_DS4, 8,
    NOTE_E4, -8, NOTE_FS4, 8, NOTE_G4, -8, NOTE_C5, 8, NOTE_B4, -8, NOTE_G4, 8, NOTE_B4, -8, NOTE_E5, 8,
    NOTE_DS5, 1,   
    NOTE_D5, 2, REST,4, REST,8, NOTE_DS4, 8, 
    NOTE_E4, -4, REST, 8, NOTE_FS4, 8, NOTE_G4, -4, REST, 8, NOTE_DS4, 8,
    NOTE_E4, -8, NOTE_FS4, 8, NOTE_G4, -8, NOTE_C5, 8, NOTE_B4, -8, NOTE_E4, 8, NOTE_G4, -8, NOTE_B4, 8,   
    NOTE_AS4, 2, NOTE_A4, -16, NOTE_G4, -16, NOTE_E4, -16, NOTE_D4, -16, 
    NOTE_E4, -4, REST, 4,
    REST, 4, NOTE_E5, -8, NOTE_D5, 8, NOTE_B4, -8, NOTE_A4, 8, NOTE_G4, -8, NOTE_E4, -8,
    NOTE_AS4, 16, NOTE_A4, -8, NOTE_AS4, 16, NOTE_A4, -8, NOTE_AS4, 16, NOTE_A4, -8, NOTE_AS4, 16, NOTE_A4, -8,   
    NOTE_G4, -16, NOTE_E4, -16, NOTE_D4, -16, NOTE_E4, 16, NOTE_E4, 16, NOTE_E4, 2,
  };

  int tempo = 120;
  int notes = sizeof(melody) / sizeof(melody[0]) / 2;
  int wholenote = (60000 * 4) / tempo;
  int divider = 0, noteDuration = 0;

  tg.stop();
  td.stop();
  digitalWrite(where_led_recorded, HIGH);
  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {
    divider = melody[thisNote + 1];
    if (divider > 0) {
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; // increases the duration in half for dotted notes
    }
    td.play(melody[thisNote], noteDuration * 0.9);
    delay(noteDuration);
    tg.stop();
    td.stop();
  }
  digitalWrite(where_led_recorded, LOW);
};
// Theme by Masato Nakamura, arranged by Teddy Mason




/*
Si jamais on est à court d'idée :
https://github.com/robsoncouto/arduino-songs
*/
