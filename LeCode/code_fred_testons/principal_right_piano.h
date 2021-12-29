/*********************************************************************
 *          On retrouve ici tout ce qui concerne en
 *         particulier le piano principal (à droite).
*********************************************************************/


/*
const int touche_right_1 = ;
const int touche_right_2 = ;
const int touche_right_3 = ;
const int touche_right_4 = ;
const int touche_right_5 = ;
const int touche_right_6 = ;
const int touche_right_7 = ;
const int touche_right_8 = ;
const int touche_right_9 = ;
const int touche_right_10 = ;
const int touche_right_11 = ;
const int touche_right_12 = ;
const int touche_right_13 = ;
const int jsp_1_r = ;
const int jsp_2_r = ;
const int jsp_3_r = ;
const int jsp_4_r = ;
const int jsp_5_r = ;
const int jsp_6_r = ;
const int jsp_7_r = ;
const int jsp_8_r = ;
*/

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
bool j1r = LOW;
bool j2r = LOW;
bool j3r = LOW;
bool j4r = LOW;
bool j5r = LOW;
bool j6r = LOW;
bool j7r = LOW;
bool j8r = LOW;

bool tr1_correcty_played;
bool tr2_correcty_played;
bool tr3_correcty_played;
bool tr4_correcty_played;
bool tr5_correcty_played;
bool tr6_correcty_played;
bool tr7_correcty_played;
bool tr8_correcty_played;
bool tr9_correcty_played;
bool tr10_correcty_played;
bool tr11_correcty_played;
bool tr12_correcty_played;
bool tr13_correcty_played;
bool tr_played;


const int buzzer_right = 2;
Tone right_tone;

void test_buzzer_right(int t=100) {
  buzzer_test(right_tone, the_set[6], t);
};


void right_piano_initializing() {
  /*
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
  pinMode(jsp_1_r, INPUT);
  pinMode(jsp_2_r, INPUT);
  pinMode(jsp_3_r, INPUT);
  pinMode(jsp_4_r, INPUT);
  pinMode(jsp_5_r, INPUT);
  pinMode(jsp_6_r, INPUT);
  pinMode(jsp_7_r, INPUT);
  pinMode(jsp_8_r, INPUT);
  right_tone.begin(buzzer_right);
  */
  /*Pas de pinMode() pour les buzzers !
  La bibliothèque <Tone.h> s'en charge !*/
};


void right_t_update() {
  /*
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

  tr1_correcty_played = truth_and(tr1, tr2, tr3, tr4, tr5, tr6, tr7, tr8, tr9, tr10, tr11, tr12, tr13);
  tr2_correcty_played = truth_and(tr2, tr3, tr4, tr5, tr6, tr7, tr8, tr9, tr10, tr11, tr12, tr13, tr1);
  tr3_correcty_played = truth_and(tr3, tr4, tr5, tr6, tr7, tr8, tr9, tr10, tr11, tr12, tr13, tr1, tr2);
  tr4_correcty_played = truth_and(tr4, tr5, tr6, tr7, tr8, tr9, tr10, tr11, tr12, tr13, tr1, tr2, tr3);
  tr5_correcty_played = truth_and(tr5, tr6, tr7, tr8, tr9, tr10, tr11, tr12, tr13, tr1, tr2, tr3, tr4);
  tr6_correcty_played = truth_and(tr6, tr7, tr8, tr9, tr10, tr11, tr12, tr13, tr1, tr2, tr3, tr4, tr5);
  tr7_correcty_played = truth_and(tr7, tr8, tr9, tr10, tr11, tr12, tr13, tr1, tr2, tr3, tr4, tr5, tr6);
  tr8_correcty_played = truth_and(tr8, tr9, tr10, tr11, tr12, tr13, tr1, tr2, tr3, tr4, tr5, tr6, tr7);
  tr9_correcty_played = truth_and(tr9, tr10, tr11, tr12, tr13, tr1, tr2, tr3, tr4, tr5, tr6, tr7, tr8);
  tr10_correcty_played = truth_and(tr10, tr11, tr12, tr13, tr1, tr2, tr3, tr4, tr5, tr6, tr7, tr8, tr9);
  tr11_correcty_played = truth_and(tr11, tr12, tr13, tr1, tr2, tr3, tr4, tr5, tr6, tr7, tr8, tr9, tr10);
  tr12_correcty_played = truth_and(tr12, tr13, tr1, tr2, tr3, tr4, tr5, tr6, tr7, tr8, tr9, tr10, tr11);
  tr13_correcty_played = truth_and(tr13, tr1, tr2, tr3, tr4, tr5, tr6, tr7, tr8, tr9, tr10, tr11, tr12);

  tr_played = (tr1 || tr2 || tr3 || tr4 || tr5 || tr6 || tr7 || tr8 || tr9 || tr10 || tr11 || tr12 || tr13);
  */
};

bool correct_right_playing() {
  bool a = (tr1_correcty_played || tr2_correcty_played || tr3_correcty_played || tr4_correcty_played);
  bool b = (tr5_correcty_played || tr6_correcty_played || tr7_correcty_played);
  bool c = (tr8_correcty_played || tr9_correcty_played || tr10_correcty_played);
  bool d = (tr11_correcty_played || tr12_correcty_played || tr13_correcty_played);
  /*correct_left_playing() retourne HIGH si et seulement si
  UNE SEULE touche du piano de gauche n'est pressée !*/
  return (a || b || c || d);
};

void right_piano_checking() {
  /*
  right_t_update();

  while (tr_played) {
    if (correct_right_playing()) {
      test_buzzer_right();
      
      //Je sais quoi mettre ici, juste pas encore eu le temps...
      
      Serial.println("Piano droite principal manié correctement");

      right_t_update();
    }
  }
  right_tone.stop();
  */
};
