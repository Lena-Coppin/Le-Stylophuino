/*********************************************************************
 *                 On retrouve ici tout ce qui gère
 *                le système de LED (écran compris).
*********************************************************************/


const int where_led_on_off = 13;
const int where_led_B_b = 12;
const int where_led_G_b = 11;
const int where_led_R_b = 10;
const int where_led_B_m = 9;
const int where_led_G_m = 8;
const int where_led_R_m = 7;
const int where_led_bend = 6;
const int where_led_tempo = 5;
const int where_led_recorded = 4;
const int where_led_rhythm = 3;


const int DIN_pin = 27;
const int CS_pin = 25;
const int CLK_pin = 23;

int one[8] = {0x00, 0x00, 0x18, 0x28, 0x08, 0x08, 0x08, 0x00};
int two[8] = {0x00, 0x00, 0x18, 0x24, 0x08, 0x10, 0x3C, 0x00};
int three[8] = {0x00, 0x00, 0x38, 0x04, 0x1C, 0x04, 0x38, 0x00};
int four[8] = {0x00, 0x00, 0x24, 0x24, 0x3C, 0x04, 0x04, 0x00};
int five[8] = {0x00, 0x00, 0x3C, 0x20, 0x3C, 0x04, 0x3C, 0x00};
int six[8] = {0x00, 0x00, 0x18, 0x20, 0x38, 0x24, 0x18, 0x00};
int seven[8] = {0x00, 0x00, 0x38, 0x04, 0x08, 0x10, 0x20, 0x00};
int amongus[8] = {0x1C, 0x22, 0x66, 0xA9, 0xA6, 0xE2, 0x2A, 0x14};
int ledaffiche[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};


int int_to_hex(int x) {
  //On se trouve sur une des huit lignes de l'écran.
  switch (x) {
    case 8:
      return 0x01;  //LED sur la huitième case
      break;
    case 7:
      return 0x02;  //LED sur la septième case
      break;
    case 6:
      return 0x04;  //LED sur la sixième case
      break;
    case 5:
      return 0x08;  //LED sur la cinquième case
      break;
    case 4:
      return 0x10;  //LED sur la quatrième case
      break;
    case 3:
      return 0x20;  //LED sur la troisième case
      break;
    case 2:
      return 0x40;  //LED sur la deuxième case
      break;
    case 1:
      return 0x80;  //LED sur la première case
      break;
  }
};


void write_pix(int data) {
  digitalWrite(CS_pin, LOW);
  for (int i = 0; i < 8; i++) {
    digitalWrite(CLK_pin, LOW);
    digitalWrite(DIN_pin, data & 0x80);   //masquage de donnée
    data = data << 1;                     //on décale les bits vers la gauche
    digitalWrite(CLK_pin, HIGH);
  }
};

void write_line(int adress, int data) {
  digitalWrite(CS_pin, LOW);
  write_pix(adress);
  write_pix(data);
  digitalWrite(CS_pin, HIGH);
};

void tornare_a_dritto(int t) {
  byte b_i[8], b_f[8];
  for (int i = 0; i <= 7; i++) {b_i[i] = byte(ledaffiche[i]);}
  do {
      for (int n = 0; n <= 7; n++) {
        for (int m = 7; m >= 0; m--) {
          bitWrite(b_f[n], m, bitRead(b_i[m], 7-n));
        }
      }
      t -= 1;
  } while (t > 0);
  for (int i = 0; i <= 7; i++) {ledaffiche[i] = int(b_f[i]);}
};

void write_matrix(bool normal=HIGH, char image='\0', int tournoite=4) {
  if (normal) {
    bool salto = HIGH;
    if (tournoite != tournement_total) {
      if ((tournoite < 4) && (tournoite >= 0)) {tournement_total = tournoite;}
    else {salto = LOW;}
    }
    switch (image) {
      case '2':
        for (int i = 0; i <= 7; i++) {ledaffiche[i] = two[i];}
        break;
      case '3':
        for (int i = 0; i <= 7; i++) {ledaffiche[i] = three[i];}
        break;
      case '4':
        for (int i = 0; i <= 7; i++) {ledaffiche[i] = four[i];}
        break;
      case '5':
        for (int i = 0; i <= 7; i++) {ledaffiche[i] = five[i];}
        break;
      case '6':
        for (int i = 0; i <= 7; i++) {ledaffiche[i] = six[i];}
        break;
      case '7':
        for (int i = 0; i <= 7; i++) {ledaffiche[i] = seven[i];}
        break;
      case 's':
        for (int i = 0; i <= 7; i++) {ledaffiche[i] = amongus[i];}
      break;
    }
    if (salto) {tornare_a_dritto(tournement_total);}
  }
  else {for (int i = 0; i <= 7; i++) {ledaffiche[i] = 0x00;}}
  for (int i = 0; i <= 7; i++) {write_line(i+1, ledaffiche[i]);}
};


void screenitialisation() {
  write_line(0x09, 0x00); //decoding BCD
  write_line(0X0A, 0x01); //brightness
  write_line(0X0B, 0x07); //scanlimit 8leds
  write_line(0X0C, 0x01); //power-down mode -> 0; normal mode -> 1
  write_line(0X0F, 0x00);
  write_matrix(LOW);
};


/*
Source du programme pour la prise en main de l'écran 8*8 leds :
https://www.aranacorp.com/fr/utilisation-dune-matrice-de-led-8x8-avec-arduino/
*/
