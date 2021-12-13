#include "pitches.h"

int notes[85] = {
  NOTE_C1,
  NOTE_CS1,
  NOTE_D1,
  NOTE_DS1,
  NOTE_E1,
  NOTE_F1,
  NOTE_FS1,
  NOTE_G1,
  NOTE_GS1,
  NOTE_A1,
  NOTE_AS1,
  NOTE_B1,
  NOTE_C2,
  NOTE_CS2,
  NOTE_D2,
  NOTE_DS2,
  NOTE_E2,
  NOTE_F2,
  NOTE_FS2,
  NOTE_G2,
  NOTE_GS2,
  NOTE_A2,
  NOTE_AS2,
  NOTE_B2,
  NOTE_C3,
  NOTE_CS3,
  NOTE_D3,
  NOTE_DS3,
  NOTE_E3,
  NOTE_F3,
  NOTE_FS3,
  NOTE_G3,
  NOTE_GS3,
  NOTE_A3,
  NOTE_AS3,
  NOTE_B3,
  NOTE_C4,
  NOTE_CS4,
  NOTE_D4,
  NOTE_DS4,
  NOTE_E4,
  NOTE_F4,
  NOTE_FS4,
  NOTE_G4,
  NOTE_GS4,
  NOTE_A4,
  NOTE_AS4,
  NOTE_B4,
  NOTE_C5,
  NOTE_CS5,
  NOTE_D5,
  NOTE_DS5,
  NOTE_E5,
  NOTE_F5,
  NOTE_FS5,
  NOTE_G5,
  NOTE_GS5,
  NOTE_A5,
  NOTE_AS5,
  NOTE_B5,
  NOTE_C6,
  NOTE_CS6,
  NOTE_D6,
  NOTE_DS6,
  NOTE_E6,
  NOTE_F6,
  NOTE_FS6,
  NOTE_G6,
  NOTE_GS6,
  NOTE_A6,
  NOTE_AS6,
  NOTE_B6,
  NOTE_C7,
  NOTE_CS7,
  NOTE_D7,
  NOTE_DS7,
  NOTE_E7,
  NOTE_F7,
  NOTE_FS7,
  NOTE_G7,
  NOTE_GS7,
  NOTE_A7,
  NOTE_AS7,
  NOTE_B7,
  NOTE_C8
};


int octave[13] = {};

void choosen_octave(int i){
  /*L'entier i est compris entre 1 et 7 inclus.*/
  int index = 0;
  for (int n = 0; n < 13; n++){
    index = n + (i-1) * 12;
    /*L'entier index est compris entre 0 et 84 inclus.
    Il parcourt 13 valeurs consécutives,
    en commençant et terminant par un multiple de 12.*/
    octave[n] = notes[index];
    }
};


char dico_notes_str[] = {'A','B','C','D','E','F','G','S'};

char print_note (int i) {
  /*i est compris entre 0 et 84 car c'est l'indice de la note de la liste notes[]*/
  char type_note;
  char numero_note;
  int i_bis = i % 12;             //i_bis est compris entre 0 et 11 inclus
  int i_ter = floor(i / 12) + 1;  //i_ter est compris entre 1 et 8 inclus (floor(5.7) = 5; floor(-6.9) = -7; floor(1.0) = 1)
  
  switch (i_bis) {
    case 1:
      type_note = dico_notes_str[3];                      //"C"
      break;
    case 2:
      type_note = dico_notes_str[3] + dico_notes_str[8];  //"CS"
      break;
    case 3:
      type_note = dico_notes_str[4];                      //"D"
      break;
    case 4:
      type_note = dico_notes_str[4] + dico_notes_str[8];  //"DS"
      break;
    case 5:
      type_note = dico_notes_str[5];                      //"E"
      break;
    case 6:
      type_note = dico_notes_str[6];                      //"F"
      break;
    case 7:
      type_note = dico_notes_str[6] + dico_notes_str[8];  //"FS"
      break;
    case 8:
      type_note = dico_notes_str[7];                      //"G"
      break;
    case 9:
      type_note = dico_notes_str[7] + dico_notes_str[8];  //"GS"
      break;
    case 10:
      type_note = dico_notes_str[1];                      //"A"
      break;
    case 11:
      type_note = dico_notes_str[1] + dico_notes_str[8];  //"AS"
      break;
    case 0:
      type_note = dico_notes_str[2];                      //"B"
      break;
    }

  switch (i_ter) {
    case 1:
      numero_note = '1';
      break;
    case 2:
      numero_note = '2';
      break;
    case 3:
      numero_note = '3';
      break;
    case 4:
      numero_note = '4';
      break;
    case 5:
      numero_note = '5';
      break;
    case 6:
      numero_note = '6';
      break;
    case 7:
      numero_note = '7';
      break;
    case 8:
      numero_note = '8';
      break;
    }
  
  return type_note + numero_note;
  }
