/*********************************************************************
 *          On retrouve ici tout ce qui concerne en
 *         particulier le piano principal (à droite).
*********************************************************************/



const int touche_right_1 = 53;
const int touche_right_2 = 51;
const int touche_right_3 = 49;
const int touche_right_4 = 47;
const int touche_right_5 = 45;
const int touche_right_6 = 43;
const int touche_right_7 = 41;
const int touche_right_8 = 39;
const int touche_right_9 = 37;
const int touche_right_10 = 35;
const int touche_right_11 = 33;
const int touche_right_12 = 31;
const int touche_right_13 = 29;


bool tr1;
bool tr2;
bool tr3;
bool tr4;
bool tr5;
bool tr6;
bool tr7;
bool tr8;
bool tr9;
bool tr10;
bool tr11;
bool tr12;
bool tr13;


bool tr1_correctly_played;
bool tr2_correctly_played;
bool tr3_correctly_played;
bool tr4_correctly_played;
bool tr5_correctly_played;
bool tr6_correctly_played;
bool tr7_correctly_played;
bool tr8_correctly_played;
bool tr9_correctly_played;
bool tr10_correctly_played;
bool tr11_correctly_played;
bool tr12_correctly_played;
bool tr13_correctly_played;
bool tr_played;


const int buzzer_right = 27;
Tone right_tone;

void test_buzzer_right(int t=100) {
  buzzer_test(right_tone, the_set[6], t);
};


void right_piano_initializing() {

  pinMode(touche_right_1, INPUT);
  pinMode(touche_right_2, INPUT);
  pinMode(touche_right_3, INPUT);
  pinMode(touche_right_4, INPUT);
  pinMode(touche_right_5, INPUT);
  pinMode(touche_right_6, INPUT);
  pinMode(touche_right_7, INPUT);
  pinMode(touche_right_8, INPUT);
  pinMode(touche_right_9, INPUT);
  pinMode(touche_right_10, INPUT);
  pinMode(touche_right_11, INPUT);
  pinMode(touche_right_12, INPUT);
  pinMode(touche_right_13, INPUT);
  right_tone.begin(buzzer_right);

  /*Pas de pinMode() pour les buzzers !
  La bibliothèque <Tone.h> s'en charge !*/
};


void right_t_update() {
  tr1 = digitalRead(touche_right_1);
  tr2 = digitalRead(touche_right_2);
  tr3 = digitalRead(touche_right_3);
  tr4 = digitalRead(touche_right_4);
  tr5 = digitalRead(touche_right_5);
  tr6 = digitalRead(touche_right_6);
  tr7 = digitalRead(touche_right_7);
  tr8 = digitalRead(touche_right_8);
  tr9 = digitalRead(touche_right_9);
  tr10 = digitalRead(touche_right_10);
  tr11 = digitalRead(touche_right_11);
  tr12 = digitalRead(touche_right_12);
  tr13 = digitalRead(touche_right_13);

  tr1_correctly_played = truth_and(tr1, tr2, tr3, tr4, tr5, tr6, tr7, tr8, tr9, tr10, tr11, tr12, tr13);
  tr2_correctly_played = truth_and(tr2, tr3, tr4, tr5, tr6, tr7, tr8, tr9, tr10, tr11, tr12, tr13, tr1);
  tr3_correctly_played = truth_and(tr3, tr4, tr5, tr6, tr7, tr8, tr9, tr10, tr11, tr12, tr13, tr1, tr2);
  tr4_correctly_played = truth_and(tr4, tr5, tr6, tr7, tr8, tr9, tr10, tr11, tr12, tr13, tr1, tr2, tr3);
  tr5_correctly_played = truth_and(tr5, tr6, tr7, tr8, tr9, tr10, tr11, tr12, tr13, tr1, tr2, tr3, tr4);
  tr6_correctly_played = truth_and(tr6, tr7, tr8, tr9, tr10, tr11, tr12, tr13, tr1, tr2, tr3, tr4, tr5);
  tr7_correctly_played = truth_and(tr7, tr8, tr9, tr10, tr11, tr12, tr13, tr1, tr2, tr3, tr4, tr5, tr6);
  tr8_correctly_played = truth_and(tr8, tr9, tr10, tr11, tr12, tr13, tr1, tr2, tr3, tr4, tr5, tr6, tr7);
  tr9_correctly_played = truth_and(tr9, tr10, tr11, tr12, tr13, tr1, tr2, tr3, tr4, tr5, tr6, tr7, tr8);
  tr10_correctly_played = truth_and(tr10, tr11, tr12, tr13, tr1, tr2, tr3, tr4, tr5, tr6, tr7, tr8, tr9);
  tr11_correctly_played = truth_and(tr11, tr12, tr13, tr1, tr2, tr3, tr4, tr5, tr6, tr7, tr8, tr9, tr10);
  tr12_correctly_played = truth_and(tr12, tr13, tr1, tr2, tr3, tr4, tr5, tr6, tr7, tr8, tr9, tr10, tr11);
  tr13_correctly_played = truth_and(tr13, tr1, tr2, tr3, tr4, tr5, tr6, tr7, tr8, tr9, tr10, tr11, tr12);

  tr_played = (tr1 || tr2 || tr3 || tr4 || tr5 || tr6 || tr7 || tr8 || tr9 || tr10 || tr11 || tr12 || tr13);
};

bool correct_right_playing() {
  bool a = (tr1_correctly_played || tr2_correctly_played || tr3_correctly_played || tr4_correctly_played);
  bool b = (tr5_correctly_played || tr6_correctly_played || tr7_correctly_played);
  bool c = (tr8_correctly_played || tr9_correctly_played || tr10_correctly_played);
  bool d = (tr11_correctly_played || tr12_correctly_played || tr13_correctly_played);
  /*correct_left_playing() retourne HIGH si et seulement si
  UNE SEULE touche du piano de gauche n'est pressée !*/
  return (a || b || c || d);
};



void right_play(int t=1000) {
  int i; 
  if (tr1_correctly_played) {i = 0;}
  else if (tr2_correctly_played) {i = 1;}
  else if (tr3_correctly_played) {i = 2;}
  else if (tr4_correctly_played) {i = 3;}
  else if (tr5_correctly_played) {i = 4;}
  else if (tr6_correctly_played) {i = 5;}
  else if (tr7_correctly_played) {i = 6;}
  else if (tr8_correctly_played) {i = 7;}
  else if (tr9_correctly_played) {i = 8;}
  else if (tr10_correctly_played) {i = 9;}
  else if (tr11_correctly_played) {i = 10;}
  else if (tr12_correctly_played) {i = 11;}
  else if (tr13_correctly_played) {i = 12;}
  right_tone.play(actual_frequencies[i], t);
};



//Ce qui est ci-dessous ne sert maintenant plus.
/*
void right_piano_checking() {
  right_t_update();
  while (tr_played) {
    if (correct_right_playing()) {
      actual_frequencies_update();

      right_play();

    }
    right_t_update();
    //commands();
  }
  right_tone.stop();
};
*/
