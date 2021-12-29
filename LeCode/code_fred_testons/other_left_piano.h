/*********************************************************************
 *          On retrouve ici tout ce qui concerne en
 *          particulier le second piano (à gauche).
*********************************************************************/


int mini_pad[6];

const int touche_left_1 = 3;
const int touche_left_2 = 4;
const int touche_left_3 = 5;
const int touche_left_4 = 6;
const int touche_left_5 = 7;
const int touche_left_6 = 8;
const int touche_left_7 = 9;
const int touche_left_8 = 10;
const int jsp_1_l = 11;
const int jsp_2_l = 12;
const int jsp_3_l = 13;

bool tl1;
bool tl2;
bool tl3;
bool tl4;
bool tl5;
bool tl6;
bool tl7;
bool tl8;
bool j1l = LOW;
bool j2l = LOW;
bool j3l = LOW;

bool tl1_correcty_played;
bool tl2_correcty_played;
bool tl3_correcty_played;
bool tl4_correcty_played;
bool tl5_correcty_played;
bool tl6_correcty_played;
bool tl7_correcty_played;
bool tl8_correcty_played;
bool tl_played;

bool msg_annonce = LOW;


const int buzzer_left = 2;
Tone left_tone;

void test_buzzer_left(int t=100) {
  buzzer_test(left_tone, the_set[7], t);
};


void left_piano_initializing() {
  pinMode(touche_left_1, INPUT);
  pinMode(touche_left_2, INPUT);
  pinMode(touche_left_3, INPUT);
  pinMode(touche_left_4, INPUT);
  pinMode(touche_left_5, INPUT);
  pinMode(touche_left_6, INPUT);
  pinMode(touche_left_7, INPUT);
  pinMode(touche_left_8, INPUT);
  pinMode(jsp_1_l, INPUT);
  pinMode(jsp_2_l, INPUT);
  pinMode(jsp_3_l, INPUT);
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
  tl8 = digitalRead(touche_left_8);

  tl1_correcty_played = truth_and(tl1, tl2, tl3, tl4, tl5, tl6, tl7, tl8);
  tl2_correcty_played = truth_and(tl2, tl3, tl4, tl5, tl6, tl7, tl8, tl1);
  tl3_correcty_played = truth_and(tl3, tl4, tl5, tl6, tl7, tl8, tl1, tl2);
  tl4_correcty_played = truth_and(tl4, tl5, tl6, tl7, tl8, tl1, tl2, tl3);
  tl5_correcty_played = truth_and(tl5, tl6, tl7, tl8, tl1, tl2, tl3, tl4);
  tl6_correcty_played = truth_and(tl6, tl7, tl8, tl1, tl2, tl3, tl4, tl5);
  tl7_correcty_played = truth_and(tl7, tl8, tl1, tl2, tl3, tl4, tl5, tl6);
  tl8_correcty_played = truth_and(tl8, tl1, tl2, tl3, tl4, tl5, tl6, tl7);

  tl_played = (tl1 || tl2 || tl3 || tl4 || tl5 || tl6 || tl7 || tl8);
};

bool correct_left_playing() {
  bool a = (tl1_correcty_played || tl2_correcty_played || tl3_correcty_played || tl4_correcty_played);
  bool b = (tl5_correcty_played || tl6_correcty_played || tl7_correcty_played || tl8_correcty_played);
  /*correct_left_playing() retourne HIGH si et seulement si
  UNE SEULE touche du piano de gauche n'est pressée !*/
  return (a || b);
};

void left_piano_checking() {
  left_t_update();

  while (tl_played) {
    if (correct_left_playing()) {
      test_buzzer_left();
      
      //Reste à savoir comment marche ce petit piano de gauche !

      if (!msg_annonce) {
        Serial.println("Piano gauche secondaire manié correctement");
        msg_annonce = HIGH;
        }

      left_t_update();
      commands(Serial.read());
    }
  }
  left_tone.stop();
  msg_annonce = LOW;
};
