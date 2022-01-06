/*********************************************************************
 *          On retrouve ici tout ce qui concerne en
 *          particulier le second piano (à gauche).
*********************************************************************/


const int touche_left_1 = 52;
const int touche_left_2 = 50;
const int touche_left_3 = 48;
const int touche_left_4 = 46;
const int touche_left_5 = 44;
const int touche_left_6 = 42;
const int touche_left_7 = 40;
const int mineur_left = 36;
const int majeur_left = 34;

bool tl1;
bool tl2;
bool tl3;
bool tl4;
bool tl5;
bool tl6;
bool tl7;
bool minl = LOW;
bool majl = HIGH;

bool tl1_correctly_played;
bool tl2_correctly_played;
bool tl3_correctly_played;
bool tl4_correctly_played;
bool tl5_correctly_played;
bool tl6_correctly_played;
bool tl7_correctly_played;
bool tl_played;


const int buzzer_left = 26;
Tone left_tone;

void mineur_ou_majeur() {
  bool a;
  bool b;
  a = digitalRead(mineur_left);
  b = digitalRead(majeur_left);
  if ((a && !minl) && majl) {
    minl = HIGH;
    majl = LOW;
    }
  if ((b && !majl) && minl) {
    minl = LOW;
    majl = HIGH;
    }
};

void test_buzzer_left(int t=100) {
  buzzer_test(left_tone, actual_frequencies[7], t);
};


void left_piano_initializing() {
  pinMode(touche_left_1, INPUT);
  pinMode(touche_left_2, INPUT);
  pinMode(touche_left_3, INPUT);
  pinMode(touche_left_4, INPUT);
  pinMode(touche_left_5, INPUT);
  pinMode(touche_left_6, INPUT);
  pinMode(touche_left_7, INPUT);
  pinMode(mineur_left, INPUT);
  pinMode(majeur_left, INPUT);
  left_tone.begin(buzzer_left);
  /*Pas de pinMode() pour les buzzers !
  La bibliothèque <Tone.h> s'en charge !*/
};


void left_t_update() {
  tl1 = digitalRead(touche_left_1);
  tl2 = digitalRead(touche_left_2);
  tl3 = digitalRead(touche_left_3);
  tl4 = digitalRead(touche_left_4);
  tl5 = digitalRead(touche_left_5);
  tl6 = digitalRead(touche_left_6);
  tl7 = digitalRead(touche_left_7);

  tl1_correctly_played = truth_and(tl1, tl2, tl3, tl4, tl5, tl6, tl7);
  tl2_correctly_played = truth_and(tl2, tl3, tl4, tl5, tl6, tl7, tl1);
  tl3_correctly_played = truth_and(tl3, tl4, tl5, tl6, tl7, tl1, tl2);
  tl4_correctly_played = truth_and(tl4, tl5, tl6, tl7, tl1, tl2, tl3);
  tl5_correctly_played = truth_and(tl5, tl6, tl7, tl1, tl2, tl3, tl4);
  tl6_correctly_played = truth_and(tl6, tl7, tl1, tl2, tl3, tl4, tl5);
  tl7_correctly_played = truth_and(tl7, tl1, tl2, tl3, tl4, tl5, tl6);

  tl_played = (tl1 || tl2 || tl3 || tl4 || tl5 || tl6 || tl7);
};

bool correct_left_playing() {
  bool a = (tl1_correctly_played || tl2_correctly_played || tl3_correctly_played || tl4_correctly_played);
  bool b = (tl5_correctly_played || tl6_correctly_played || tl7_correctly_played);
  /*correct_left_playing() retourne HIGH si et seulement si
  UNE SEULE touche du piano de gauche n'est pressée !*/
  return (a || b);
};

int quelles_3_touches_gauche() {
  int i;
  if (tl1_correctly_played) {i = 0;}
  else if (tl2_correctly_played) {i = 4;}
  else if (tl3_correctly_played) {i = 8;}
  else if (tl4_correctly_played) {i = 12;}
  else if (tl5_correctly_played) {i = 16;}
  else if (tl6_correctly_played) {i = 20;}
  else if (tl7_correctly_played) {i = 24;}
  return i;
};

void fast_3_times_200_update_left(int a, int b, int c) {
  int index[3] = {a, b, c};
  for (int i = 0; i < 3; i++) {
    left_tone.play(mini_pad[index[i]], 200);
    left_t_update();
    if (!tl_played || !correct_left_playing()) {break;}
    for (int j = 0; j < 4; j++) {
      delay(50);
      left_t_update();
      if (!tl_played || !correct_left_playing()) {break;}
      }
    }
};

void left_play() {
  int i = quelles_3_touches_gauche();
  int a; 
  mineur_ou_majeur();
  if (minl) {a = 1;}
  if (majl) {a = 2;}
  fast_3_times_200_update_left(i, i+a, i+3);
};

void left_piano_checking() {
  left_t_update();

  while (tl_played) {
    if (correct_left_playing()) {
      actual_frequencies_update();

      left_play();
      
      left_t_update();
      commands(Serial.read());
    }
  }
  left_tone.stop();
};
