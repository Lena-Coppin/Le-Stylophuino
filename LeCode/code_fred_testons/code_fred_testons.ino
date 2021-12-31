#include <Tone.h>   //Aka "the library that saved us"

#include "notes.h"
#include "fonctions_basiques.h"

Tone tone2;

#include "principal_right_piano.h"
#include "other_left_piano.h"

#include "melodies.h"

void setup() {
  first_initializing();
  left_piano_initializing();
  right_piano_initializing();
  
  tone2.begin(jsp_3_l);
  c_c_h(left_tone);
}

void loop() {
  commands(Serial.read());
  actual_frequencies_update();
  left_piano_checking();
}
