
#include "notes.h"

#include "fonctions_basiques.h"


void setup() {
  Serial.begin(9600);
  choosen_set(1);
}

void loop() {
  commands(Serial.read());
}
