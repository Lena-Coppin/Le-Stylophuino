/*********************************************************************
 *          On retrouve ici des séquences de notes
 *           déjà enregistrées et donc jouables.
*********************************************************************/


/*Ces sont les 4 premières notes de la chanson
"Ching Cheng Hanji" de l'artiste Dehao Zhang.*/
void c_c_h(Tone t1, char a='\0') {
  int i = 55;
  if (a=='-') {i = i - 12;}
  t1.stop();
  t1.play(notes[i], 225);
  delay(325);
  t1.play(notes[i-4], 225);
  delay(325);
  t1.play(notes[i-2], 225);
  delay(325);
  t1.play(notes[i], 225);
  delay(1000);
  t1.stop();
};
