/*********************************************************************
 *          On retrouve ici un regroupement de code
 *           provenant des deux pianos, permettant
 *            ainsi le fonctionnement général des
 *                  touches du variophuino.
*********************************************************************/


void pianos_checking() {
  left_t_update();
  right_t_update();
  while (tr_played) {
    if (correct_left_playing() || correct_right_playing()) {
      actual_frequencies_update();
      
    }
  }
  left_tone.stop();
  right_tone.stop();
};
