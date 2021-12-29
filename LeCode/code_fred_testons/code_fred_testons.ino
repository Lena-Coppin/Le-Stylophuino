#include <Tone.h>   //Aka "the library that saved us"

#include "notes.h"
#include "fonctions_basiques.h"

#include "principal_right_piano.h"
#include "other_left_piano.h"

Tone tone2;

void setup() {
  first_initializing();
  left_piano_initializing();
  right_piano_initializing();
  
  //tone2.begin(jsp_3_l);
}

void loop() {
  commands(Serial.read());
  left_piano_checking();
}
