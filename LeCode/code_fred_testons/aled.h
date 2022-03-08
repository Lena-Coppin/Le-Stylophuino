/*********************************************************************
 *                 On retrouve ici tout ce qui gère
 *                le système de LED (écran compris).
*********************************************************************/


const int where_led_on_off = 13;    //pas besoin de coder cet led
const int where_led_B_b = 12;
const int where_led_G_b = 11;
const int where_led_R_b = 10;
const int where_led_B_m = 9;
const int where_led_G_m = 8;
const int where_led_R_m = 7;
const int where_led_bend = 6;
const int where_led_tempo = 5;
const int where_led_recorded = 4;
const int where_led_for_bluetooth = 3;

unsigned int led_B_b_value = 0;
unsigned int led_G_b_value = 0;
unsigned int led_R_b_value = 0;
unsigned int led_B_m_value = 0;
unsigned int led_G_m_value = 0;
unsigned int led_R_m_value = 0;


const int DIN_pin = 25;
const int CS_pin = 24;
const int CLK_pin = 23;

int zero[8] = {0x00, 0x00, 0x18, 0x24, 0x24, 0x24, 0x18, 0x00};     // largeur: 4
int one[8] = {0x00, 0x00, 0x10, 0x30, 0x50, 0x10, 0x10, 0x00};      // largeur: 3
int two[8] = {0x00, 0x00, 0x18, 0x24, 0x08, 0x10, 0x3C, 0x00};      // largeur: 4
int three[8] = {0x00, 0x00, 0x38, 0x04, 0x1C, 0x04, 0x38, 0x00};    // largeur: 4
int four[8] = {0x00, 0x00, 0x24, 0x24, 0x3C, 0x04, 0x04, 0x00};     // largeur: 4
int five[8] = {0x00, 0x00, 0x3C, 0x20, 0x3C, 0x04, 0x3C, 0x00};     // largeur: 4
int six[8] = {0x00, 0x00, 0x18, 0x20, 0x38, 0x24, 0x18, 0x00};      // largeur: 4
int seven[8] = {0x00, 0x00, 0x38, 0x04, 0x08, 0x10, 0x20, 0x00};    // largeur: 4
int eight[8] = {0x00, 0x00, 0x18, 0x24, 0x18, 0x24, 0x18, 0x00};    // largeur: 4
int nine[8] = {0x00, 0x00, 0x18, 0x24, 0x1C, 0x04, 0x18, 0x00};     // largeur: 4

int A[8] = {0x00, 0x00, 0x18, 0x24, 0x3C, 0x24, 0x24, 0x00};      // largeur: 4
int C[8] = {0x00, 0x00, 0x1C, 0x20, 0x20, 0x20, 0x1C, 0x00};      // largeur: 4
int E[8] = {0x00, 0x00, 0x3C, 0x20, 0x38, 0x20, 0x3C, 0x00};      // largeur: 4
int I[8] = {0x00, 0x00, 0x10, 0x10, 0x10, 0x10, 0x10, 0x00};      // largeur: 1
int J[8] = {0x00, 0x00, 0x3C, 0x08, 0x08, 0x28, 0x10, 0x00};      // largeur: 4
int L[8] = {0x00, 0x00, 0x20, 0x20, 0x20, 0x20, 0x3C, 0x00};      // largeur: 4
int N[8] = {0x00, 0x00, 0x24, 0x34, 0x3C, 0x2C, 0x24, 0x00};      // largeur: 4
int O[8] = {0x00, 0x00, 0x18, 0x24, 0x24, 0x24, 0x18, 0x00};      // largeur: 4
int P[8] = {0x00, 0x00, 0x38, 0x24, 0x38, 0x20, 0x20, 0x00};      // largeur: 4
int R[8] = {0x00, 0x00, 0x38, 0x24, 0x38, 0x28, 0x24, 0x00};      // largeur: 4
int T[8] = {0x00, 0x00, 0x38, 0x10, 0x10, 0x10, 0x10, 0x00};      // largeur: 3
int U[8] = {0x00, 0x00, 0x24, 0x24, 0x24, 0x24, 0x18, 0x00};      // largeur: 4

int amongus[8] = {0x1C, 0x22, 0x66, 0xA9, 0xA6, 0xE2, 0x2A, 0x14};  // totu l'écran

int ledaffiche[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};


void led_b_shine(unsigned int r=led_R_b_value, unsigned int g=led_G_b_value, unsigned int b=led_B_b_value) {
  led_R_b_value = r;
  led_G_b_value = g;
  led_B_b_value = b;
  analogWrite(where_led_B_b, led_B_b_value);
  analogWrite(where_led_G_b, led_G_b_value);
  analogWrite(where_led_R_b, led_R_b_value);
};


void led_m_shine(unsigned int r=led_R_m_value, unsigned int g=led_G_m_value, unsigned int b=led_B_m_value) {
  led_R_m_value = r;
  led_G_m_value = g;
  led_B_m_value = b;
  analogWrite(where_led_B_m, led_B_m_value);
  analogWrite(where_led_G_m, led_G_m_value);
  analogWrite(where_led_R_m, led_R_m_value);
};


char totu[23] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                 'A', 'C', 'E', 'I', 'J', 'L', 'N', 'O', 'P', 'R', 'T', 'U',
                 's'};


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

void tornare_a_dritto() {
  byte b_i[8], b_f[8];
  for (int i = 0; i <= 7; i++) {b_i[i] = byte(ledaffiche[i]);}
  int t = tournement_total;
  while (t > 0) {
    //Serial.println();
    for (int n = 0; n <= 7; n++) {
      for (int m = 7; m >= 0; m--) {
        bitWrite(b_f[n], m, bitRead(b_i[m], 7-n));
        //Serial.print(bitRead(b_f[n], m));
      }
      //Serial.println();
    }
    //Serial.println();
    for (int i = 0; i <= 7; i++) {b_i[i] = b_f[i];}
    t -= 1;
  }
  for (int i = 0; i <= 7; i++) {ledaffiche[i] = int(b_f[i]);}
};

byte caracargeur = 0;

void char_switch_image(char a) {
  switch (a) {
    case '0':
      for (int i = 0; i <= 7; i++) {ledaffiche[i] = zero[i];}
      caracargeur = 4;
      break;
    case '1':
      for (int i = 0; i <= 7; i++) {ledaffiche[i] = one[i];}
      caracargeur = 3;
      break;
    case '2':
      for (int i = 0; i <= 7; i++) {ledaffiche[i] = two[i];}
      caracargeur = 4;
      break;
    case '3':
      for (int i = 0; i <= 7; i++) {ledaffiche[i] = three[i];}
      caracargeur = 4;
      break;
    case '4':
      for (int i = 0; i <= 7; i++) {ledaffiche[i] = four[i];}
      caracargeur = 4;
      break;
    case '5':
      for (int i = 0; i <= 7; i++) {ledaffiche[i] = five[i];}
      caracargeur = 4;
      break;
    case '6':
      for (int i = 0; i <= 7; i++) {ledaffiche[i] = six[i];}
      caracargeur = 4;
      break;
    case '7':
      for (int i = 0; i <= 7; i++) {ledaffiche[i] = seven[i];}
      caracargeur = 4;
      break;
    case '8':
      for (int i = 0; i <= 7; i++) {ledaffiche[i] = eight[i];}
      caracargeur = 4;
      break;
    case '9':
      for (int i = 0; i <= 7; i++) {ledaffiche[i] = nine[i];}
      caracargeur = 4;
      break;
    case 'A':
      for (int i = 0; i <= 7; i++) {ledaffiche[i] = A[i];}
      caracargeur = 4;
      break;
    case 'C':
      for (int i = 0; i <= 7; i++) {ledaffiche[i] = C[i];}
      caracargeur = 4;
      break;
    case 'E':
      for (int i = 0; i <= 7; i++) {ledaffiche[i] = E[i];}
      caracargeur = 4;
      break;
    case 'I':
      for (int i = 0; i <= 7; i++) {ledaffiche[i] = I[i];}
      caracargeur = 1;
      break;
    case 'J':
      for (int i = 0; i <= 7; i++) {ledaffiche[i] = J[i];}
      caracargeur = 4;
      break;
    case 'L':
      for (int i = 0; i <= 7; i++) {ledaffiche[i] = L[i];}
      caracargeur = 4;
      break;
    case 'N':
      for (int i = 0; i <= 7; i++) {ledaffiche[i] = N[i];}
      caracargeur = 4;
      break;
    case 'O':
      for (int i = 0; i <= 7; i++) {ledaffiche[i] = O[i];}
      caracargeur = 4;
      break;
    case 'P':
      for (int i = 0; i <= 7; i++) {ledaffiche[i] = P[i];}
      caracargeur = 4;
      break;
    case 'R':
      for (int i = 0; i <= 7; i++) {ledaffiche[i] = R[i];}
      caracargeur = 4;
      break;
    case 'T':
      for (int i = 0; i <= 7; i++) {ledaffiche[i] = T[i];}
      caracargeur = 3;
      break;
    case 'U':
      for (int i = 0; i <= 7; i++) {ledaffiche[i] = U[i];}
      caracargeur = 4;
      break;
    case 's':
      for (int i = 0; i <= 7; i++) {ledaffiche[i] = amongus[i];}
      caracargeur = 8;
      break;
  }
};

void write_matrix(bool normal=HIGH, char image='\0', int tournoite=4, bool texte=LOW) {
  bool salto = LOW;
  if ((tournoite != tournement_total) && ((tournoite < 4)&&(tournoite >= 0))) {
    tournement_total = tournoite;
  }
  if (tournement_total > 0) {salto = HIGH;}
  if (normal) {
    if (image != 0) {ancienne_image = image;}
    if (!texte) {char_switch_image(ancienne_image);}
    if (salto) {tornare_a_dritto();}
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
  write_matrix(LOW, '\0', 2);
};


char texte[32] = {'|', 'P', 'A', 'R', '_',
                  'L', 'E', 'N', 'A', '_',
                  'C', 'O', 'P', 'P', 'I', 'N', '_',
                  'E', 'T', '_',
                  'J', 'U', 'L', 'I', 'E', 'N', '_',
                  'N', 'O', 'E', 'L', '|'};


void affiche_texte(unsigned int t=250) {
  byte car[5][4] = {{0, 0, 0, 0},
                    {0, 0, 0, 0},
                    {0, 0, 0, 0},
                    {0, 0, 0, 0},
                    {0, 0, 0, 0}};
  if (texte[0] == '|') {
    write_matrix(LOW);
    delay(t);
    for (int i = 1; texte[i] != '|'; i++) {
      char_switch_image(texte[i]);
      int j = 0;
      while ((bitRead(ledaffiche[2], 7-j) == 0) &&
             (bitRead(ledaffiche[3], 7-j) == 0) && 
             (bitRead(ledaffiche[4], 7-j) == 0) &&
             (bitRead(ledaffiche[5], 7-j) == 0) &&
             (bitRead(ledaffiche[6], 7-j) == 0)) {
        j++;
      }
      for (int k = j; k < caracargeur; k++) {
        car[0][k-j] = bitRead(ledaffiche[2], 7-k);
        car[1][k-j] = bitRead(ledaffiche[3], 7-k);
        car[2][k-j] = bitRead(ledaffiche[4], 7-k);
        car[3][k-j] = bitRead(ledaffiche[5], 7-k);
        car[4][k-j] = bitRead(ledaffiche[6], 7-k);
      }
      if (i > 1) {
        for (int y = 0; y < 5; y++) {
          for (int x = 7; x > 1; x++) {
            bitWrite(ledaffiche[y+2], x, bitRead(ledaffiche[y+2], x-1));
          }
          bitWrite(ledaffiche[y+2], 0, bitRead(ledaffiche[y+2], 0));
        }
        write_matrix(HIGH, '\0', tournement_total, HIGH);
        delay(t);
      }
      for (int j = 0; j < caracargeur; j++) {
        for (int y = 0; y < 5; y++) {
          for (int x = 7; x > 1; x++) {
            bitWrite(ledaffiche[y+2], x, bitRead(ledaffiche[y+2], x-1));
          }
          bitWrite(ledaffiche[y+2], 0, bitRead(ledaffiche[y+2], 0));
        }
        write_matrix(HIGH, '\0', tournement_total, HIGH);
        delay(t);
      }
    }
  }
};



/*
Source du programme pour la prise en main de l'écran 8*8 leds :
https://www.aranacorp.com/fr/utilisation-dune-matrice-de-led-8x8-avec-arduino/
*/
