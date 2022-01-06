/*********************************************************************
 *          On retrouve ici des séquences de notes
 *           déjà enregistrées et donc jouables.
*********************************************************************/



/*Ces sont les 4 premières notes de la chanson
"Ching Cheng Hanji" de l'artiste Dehao Zhang.*/
void cch_short(Tone t1, char a='\0') {
  int i = 55;
  if (a=='_') {i = i - 24;}
  else if (a=='-') {i = i - 12;}
  else if (a=='+') {i = i + 12;}
  t1.stop();
  t1.play(notes[i], 225);
  delay(325);
  t1.play(notes[i-4], 225);
  delay(325);
  t1.play(notes[i-2], 225);
  delay(325);
  t1.play(notes[i], 225);
  delay(1225);
  t1.stop();
};



/*Voici l'hymne national de la Russie.*/
void urss(Tone t1, char a='\0') {
  int i = 43;
  if (a=='_') {i = i - 12;}
  else if (a=='-') {i = i - 12;}
  else if (a=='+') {i = i + 12;}
  
  int n1 = notes[i - 7];      //C-
  int n2 = notes[i - 5];      //D-
  int n3 = notes[i - 3];      //E-
  int n4 = notes[i - 2];      //F-
  int n5 = notes[i];          //G
  int n6 = notes[i + 2];      //A+
  int n7 = notes[i + 4];      //B+
  int n8 = notes[i + 5];      //C+
  int n9 = notes[i + 7];      //D+
  int n10 = notes[i + 9];     //E+
  int n11 = notes[i + 10];    //F+
  
  int our_melody[106] = {
    n5, n8, n5, n6, n7, n3, n3,
    n6, n5, n4, n5, n1, n1,
    n2, n2, n3, n4, n4, n5, n6, n7, n8, n9,
    n5, n10, n9, n8, n9, n7, n5,
    n8, n7, n6, n7, n3, n3,
    n6, n5, n4, n5, n1, n1,
    n8, n7, n6, n5, n7, n8, n9,
    n10, n9, n8, n7, n8, n9, n5, n5, n7, n8, n9,
    n8, n7, n6, n5, n6, n7, n3, n3, n5, n6, n7,
    n8, n6, n7, n8, n6, n7, n8, n6, n8, n11,
    n11, n10, n9, n8, n9, n10, n8, n8,
    n9, n8, n7, n6, n7, n8, n6, n6,
    n8, n7, n6, n5, n1, n5, n6, n7, n8
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
  
  t1.stop();
  for (int k = 0; k < 106; k++) {
    int duration = 2400 / reladur[k];
    t1.play(our_melody[k], duration);
    int waiting = duration * 1.30;
    delay(waiting);
    t1.stop();
    }
};
/*Comme le dit le propriétaire du Github ayant permis 
de réaliser cette fonction urss() :
"Quality USSR Anthem by Ömer Arda Kaya for all comrades"*/
