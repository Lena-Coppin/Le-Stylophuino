/*********************************************************************
 *          On retrouve ici un regroupement de code
 *           provenant des deux pianos, permettant
 *            ainsi le fonctionnement général des
 *                  touches du variophuino.
*********************************************************************/


void basic_updater() {
  int i = quelles_3_touches_gauche();
  int a; 
  mineur_ou_majeur();
  if (minl) {a = 1;}
  if (majl) {a = 2;}
  left_index[0] = i;
  left_index[1] = i+a;
  left_index[2] = i+3;
  actual_frequencies_update();
};


bool left_all_ok() {
  left_t_update();
  return (tl_played && correct_left_playing());
};

bool right_all_ok() {
  right_t_update();
  return (tr_played && correct_right_playing());
};


void super_3_times_200_updater() {
  //boucle for: 3 fois 200 millisecondes => 600 millisecondes
  for (int i = 0; i < 3; i++) {
    basic_updater();
    commands(Serial.read());
    
    if (left_all_ok()) {left_tone.play(mini_pad[left_index[i]], 200);}
    else {
      left_tone.stop();
      break;
    }
    
    if (right_all_ok()) {right_play(200);}
    else {right_tone.stop();}

    //boucle for: 4 fois 50 millisecondes => 200 millisecondes
    for (int j = 0; j < 4; j++) {
      delay(50);
      basic_updater();
      commands(Serial.read());
      
      if (!left_all_ok()) {
        left_tone.stop();
        break;
      }
      
      if (right_all_ok()) {right_play(200);}
      else {right_tone.stop();}
    }
    
    if (!left_all_ok()) {
        left_tone.stop();
        break;
    }
  }
};


void pianos_checking() {
  basic_updater();
  left_t_update();
  right_t_update();
  while (tl_played || tr_played) {
    basic_updater();
    if (correct_left_playing() || correct_right_playing()) {
      
      super_3_times_200_updater();

      basic_updater();
      if (right_all_ok()) {right_play(200);}
      else {right_tone.stop();}
    }
    left_t_update();
    right_t_update();
    commands(Serial.read());
  }
  left_tone.stop();
  right_tone.stop();
};
