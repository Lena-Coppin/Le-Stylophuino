/**********************************************************************************************
*     Voici toutes les fonctions qui permetteront le bon fonctionnement du variophuino.
*               Tous les effets non essentiels seront traités ailleurs.
**********************************************************************************************/




/*========================[PARTIE CALCULS]========================*/


double f_pitch(int n) {
  return 1.8125 * exp(0.058 * n);
};


void change_for_pitchbend(int n, int s) {
  /*s est compris entre 1 et 85 inclus.
  On garde les 8 premières valeurs de s
  possibles malgré l'inaudibilité.*/
  double gap = f_pitch(s);
  int new_gap = 0;
  
  bool c_1_semel = ((s==1)||(s==5)||(s==7)||(s==8)||(s==11)||(s==13)||(s==15)||(s==17));
  bool c_1_bis = ((s==18)||(s==20)||(s==22)||(s==24)||(s==25)||(s==27)||(s==29)||(s==31));
  bool c_1_ter = ((s==32)||(s==35)||(s==36)||(s==38)||(s==40)||(s==42)||(s==43)||(s==45));
  bool c_1_quater = ((s==47)||(s==50)||(s==51)||(s==52)||(s==54)||(s==56)||(s==59)||(s==60));
  bool c_1 = ((c_1_semel)||(c_1_bis)||(c_1_ter)||(c_1_quater));
  //La condition c_1 sera vraie si et seulement si on a besoin de ceil(gap).
  
  bool c_2 = ((s==72)||(s==73)||(s==78)||(s==79)||(s==80)||(s==82)||(s==83)||(s==84));
  //La condition c_2 sera vraie si et seulement si on a besoin de floor(gap - 1).

  if (c_1) {new_gap = ceil(gap);}   //(ceil(5.7) = 6; ceil(-6.9) = -6; ceil(1.0) = 1)
  else if (c_2) {new_gap = floor(gap - 1);}
  else if (s==85) {new_gap = NOTE_CS8 - NOTE_C8;}   //définition du 85ème écart nécessaire
  else {new_gap = floor(gap);}      //(floor(5.7) = 5; floor(-6.9) = -7; floor(1.0) = 1)

  pitchbend_variations_set[n] = new_gap;
};


void choosen_set(int i){
  if (i<=1) {i=2;}
  else if (i>=8) {i=7;}
  /*L'entier i est compris entre 2 et 7 inclus.
  i ne vaut jamais 1 car sinon les premières notes
  de the_set[] seraient inaudibles.*/
  current_set_number = i;
  int index = 0;
  for (int n = 0; n < 13; n++){
    index = n + (current_set_number - 1) * 12;
    /*L'entier index est compris entre 12 et 84 inclus.
    Il parcourt 13 valeurs consécutives,
    en commençant et terminant par un multiple de 12.*/
    the_set[n] = notes[index];  //mise à jour de the_set[]
    change_for_pitchbend(n, index+1);  //mise à jour de pitchbend_variations_set[]
    }
};


void actual_frequencies_update() {
  an0 = analogRead(where_poten);
  for (int i = 0; i < 13; i++){
    actual_frequencies[i] = the_set[i] + map(an0, 0, 1023, 0, pitchbend_variations_set[i]);
    }
};


void set_plus() {
  int csn = current_set_number;
  csn = csn + 1;
  if (csn >= 8) {csn = 2;}
  choosen_set(csn);
};


void set_moins() {
  int csn = current_set_number;
  csn = csn - 1;
  if (csn <= 1) {csn = 7;}
  choosen_set(csn);
};


void first_initializing() {
  Serial.begin(9600);
  choosen_set(2);
};


bool truth_and(bool H, bool L1=LOW, bool L2=LOW, bool L3=LOW, bool L4=LOW, bool L5=LOW, bool L6=LOW, bool L7=LOW, bool L8=LOW, bool L9=LOW, bool L10=LOW, bool L11=LOW, bool L12=LOW) {
  /*Le premier paramètre H est obligatoire.
  truth_and() peut accueillir jusqu'à
  13 paramètres, tous de type bool.
  L'ordre des paramètres est extrêmement
  important, surtout par rapport au premier.*/
  return (!L1 && !L2 && !L3 && !L4 && !L5 && !L6 && !L7 && !L8 && !L9 && !L10 && !L11 && !L12) && H;
};


void buzzer_test(Tone a, int note, int t=100) {
  //tone(buzzer, note, t);
  a.play(note, t);
  /*Il faut D'ABORD initialiser le buzzer !!*/
};


#include "effets_bluetooth.h"


/*================================================================*/



/*=======================[PARTIE AFFICHAGE]=======================*/


void print_note(int i) {
  /*i est compris entre 0 et 84 car
  c'est l'indice de la note de la liste notes[].
  Cela permet malgré tout d'afficher les 8
  premières notes (quand 0 <= i <= 7).*/
  char lettre_note;
  char diese_note;
  char numero_note;
  int i_bis = (i+1) % 12;             
  //i_bis est compris entre 0 et 11 inclus
  int i_ter = floor(i / 12) + 1;
  //i_ter est compris entre 1 et 8 inclus

  switch (i_bis) {
    case 1:
      lettre_note = 'C';    //"C"
      break;
    case 2:
      lettre_note = 'C';    //"CS"
      break;
    case 3:
      lettre_note = 'D';    //"D"
      break;
    case 4:
      lettre_note = 'D';    //"DS"
      break;
    case 5:
      lettre_note = 'E';    //"E"
      break;
    case 6:
      lettre_note = 'F';    //"F"
      break;
    case 7:
      lettre_note = 'F';    //"FS"
      break;
    case 8:
      lettre_note = 'G';    //"G"
      break;
    case 9:
      lettre_note = 'G';    //"GS"
      break;
    case 10:
      lettre_note = 'A';    //"A"
      break;
    case 11:
      lettre_note = 'A';    //"AS"
      break;
    case 0:
      lettre_note = 'B';    //"B"
      break;
    }

  if ((i_bis==2)||(i_bis==4)||(i_bis==7)||(i_bis==9)||(i_bis==11)) {
    diese_note = 'S';}
  else {diese_note = '\0';}
  //'\0' -> caractère nul

  numero_note = (char) (48+i_ter);
  /*En code ASCII, le numéro  du caractère '0' est 48.
  Les caractères suivent le même ordre que les chiffres.
  Donc le numéro du caractère '3' en ASCII est 48+3=51 par exemple.*/
  
  Serial.print(lettre_note);
  Serial.print(diese_note);
  Serial.print(numero_note);
};


void print_current_set() {
  int index = 0;
  Serial.print("Appareil actuellement réglé sur le set numéro ");
  Serial.print(current_set_number);
  Serial.println(" :");
  for (int n = 0; n < 13; n++){
    index = n + (current_set_number - 1) * 12;
    Serial.print("  ");
    print_note(index);
    if (n == 12) {Serial.println("\n");}
    else {Serial.print("\t;");}
    }
};


void print_variation_set() {
  Serial.print("Écarts associés :   [ ");
  for (int i = 0; i < 13; i++){
    Serial.print(pitchbend_variations_set[i]);
    if (i == 12) {Serial.println(" ]\n");}
    else {Serial.print(" ; ");}
  }
};


void print_truth(bool a) {
  if (a==HIGH) {Serial.println("True");}
  else {Serial.println("False");}
};


/*================================================================*/



/*=======================[PARTIE COMMANDES]=======================*/


void commands(char a) {
  switch (a) {
    case 's':
      print_current_set();
      break;
    case 'v':
      print_variation_set();
      break;
    case 'p':
      set_plus();
      break;
    case 'm':
      set_moins();
      break;
    }
};


/*================================================================*/
