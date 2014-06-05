#include <cstdlib>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "Lotto.h"
#include "Ziehung.h"
#include "MeineEingabe.h"

/**
  * Default-Konstruktor. Konstruiert ein Objekt Ziehungen mit einer 
  * zufaelligen Lottoziehung.
  */
Ziehung::Ziehung()
{
  Lotto x = Lotto();
  lottospiele.push_back(x);
}

/**
  * Konstruiert ein Objekt vom Typ Lottoziehungen mit x zufaelligen
  * Lottoziehungen. x kann aus dem Bereich von 1 bis 10000000 fei gewaehlt werden.
  * Wenn x kleiner als 1 oder groesser 10000000 ist, wird der x auf 1 gesetzt.
  * @param anzahl_der_spiele Anzahl der Lottospiele.
  */
Ziehung::Ziehung(int anzahl_der_spiele)
{
  if (anzahl_der_spiele < 1 || anzahl_der_spiele > 10000000)
    anzahl_der_spiele = 1;
  for(int i = 0; i < anzahl_der_spiele; i++)
  {
    Lotto x = Lotto();
    lottospiele.push_back(x);
  }
}

/**
  * Rechnet die Anzahl der Spiele in Jahre und Monate um und gibt die Werte auf dem Bildschirm aus.
  */
void Ziehung::anzahl_spiele_in_jahre() const
{
  double jahreplus = (double)(lottospiele.size()) / 52;
  int jahre = (int)jahreplus;
  double rest = jahreplus - jahre;
  double monate = rest * 12;
  cout << "\n\n" << lottospiele.size() << " Lottospiele entsprechen: ";
  cout << jahre << " Jahre und " << setprecision(3) << monate << " Monate.\n\n";
}

/**
  * Schreibt die Haeufigkeitsverteilung der Zahlen von 1 bis 49 auf den Bildschirm.
  */
void Ziehung::schreibe_haeufigkeitsverteilung() const
{
  int array[49] = {0};
  for(unsigned int i = 0; i < lottospiele.size(); i++)
  {
    vector<int> q = lottospiele[i].liefere_lottozahlen();
    for(unsigned int z = 0; z < q.size(); z++)
    {
      int g = q[z];
      array[g - 1] += 1;
    }
  }
  schreibe_array_als_tabelle(array, 49);
  vector<int> werte;
  for(unsigned int z = 0; z < 49; z++)
    werte.push_back(array[z]);
  int pos_min = finde_kleinesten_wert_im_Vector(werte);
  int pos_max = finde_hoechsten_wert_im_Vector(werte);
  cout << "\nDie Zahl " << pos_min + 1 << " kam mit " << werte[pos_min] << " am wenigsten vor.";
  cout << "\nDie Zahl " << pos_max + 1 << " kam mit " << werte[pos_max] << " am meisten vor.";
  cout << "\nDifferenz: " << werte[pos_max] - werte[pos_min] << " .\n";
}

/**
  * Schreibt die Minimalverteilung aller Lottoziehungen auf den Bildschirm.
  */
void Ziehung::schreibe_minimumverteilung() const
{
  int array[49] = {0};
  for(unsigned int i = 0; i < lottospiele.size(); i++)
  {
    int q = lottospiele[i].liefere_kleinste_zahl();
    array[q - 1] += 1;
  }
  schreibe_array_als_tabelle(array, 49);
}

/**
  * Schreibt die Maximalverteilung aller Lottoziehungen auf den Bildschirm.
  */
void Ziehung::schreibe_maximaverteilung() const
{
  int array[49] = {0};
  for(unsigned int i = 0; i < lottospiele.size(); i++)
  {
    int q = lottospiele[i].liefere_groesste_zahl();
    array[q - 1] += 1;
  }
  schreibe_array_als_tabelle(array, 49);
}

/**
  * Schreibt die Laengenverteilung aller Lottoziehungen auf den Bildschirm.
  */
void Ziehung::schreibe_laengenverteilung() const
{
  int array[44] = {0};
  for(unsigned int i = 0; i < lottospiele.size(); i++)
  {
    int q = lottospiele[i].liefere_differenz();
    array[q - 4] += 1;
  }
  schreibe_array_als_tabelle_plus_prozent(array, 44);
}

/**
  * Gibt wie oft die Laenge einer Lottoziehung als Zahl in ihr selbst vorkommt auf dem Bildschirm aus.
  */
void Ziehung::schreibe_auftreten_der_laenge_als_zahl() const
{
  int anzahl = 0;
  for(unsigned int i = 0; i < lottospiele.size(); i++)
    if(lottospiele[i].pruefe_ob_differenz_vorhanden() == true)
      anzahl++;
  double prozent = (double)(anzahl * 100) / (double)(lottospiele.size());
  cout << "\n\nBei " << anzahl << " von " << lottospiele.size() << " Lottospielen kam die Laenge als Zahl auf.\n";
  cout << "Das entspricht: " << fixed << setprecision(4) << prozent << " %\n";
}

/**
  * Gibt die Haeufigkeit von komplett geraden Ziehungen aller Lottospiele auf dem Bildschirm aus.
  */
void Ziehung::schreibe_haeufigkeit_der_geraden_ziehungen() const
{
  int anzahl = 0;
  for(unsigned int i = 0; i < lottospiele.size(); i++)
    if(lottospiele[i].pruefe_auf_gerade_ziehung() == true)
      anzahl++;
  double prozent = (double)(anzahl * 100) / (double)(lottospiele.size());
  cout << "\n\nBei " << anzahl << " von " << lottospiele.size() << " Lottospielen handelte es sich um eine GERADE Ziehung.\n";
  cout << "Das entspricht: " << fixed << setprecision(4) << prozent << " %\n";
}

/**
  * Schreibt die Haeufigkeit von UNGERADEN-Ziehungen aller Lottoziehungen auf den Bildschirm.
  */
void Ziehung::schreibe_haeufigkeit_der_ungeraden_ziehungen() const
{
  int anzahl = 0;
  for(unsigned int i = 0; i < lottospiele.size(); i++)
    if(lottospiele[i].pruefe_auf_ungerade_ziehung() == true)
      anzahl++;
  double prozent = (double)(anzahl * 100) / (double)(lottospiele.size());
  cout << "\n\nBei " << anzahl << " von " << lottospiele.size() << " Lottospielen handelte es sich um eine UNGERADE Ziehung.\n";
  cout << "Das entspricht: " << fixed << setprecision(4) << prozent << " %\n";
}

/**
  * Gibt die Haeufigkeit von Primziehungen aller Lottoziehungen auf den Bildschirm aus.
  */
void Ziehung::schreibe_haeufigkeit_der_primziehungen() const
{
  int anzahl = 0;
  for(unsigned int i = 0; i < lottospiele.size(); i++)
    if(lottospiele[i].pruefe_auf_primziehung() == true)
      anzahl++;
  double prozent = (double)(anzahl * 100) / (double)(lottospiele.size());
  cout << "\n\nBei " << anzahl << " von " << lottospiele.size() << " Lottospielen handelte es sich um eine Primziehung.\n";
  cout << "Das entspricht: " << fixed << setprecision(4) << prozent << " %\n";
}

/**
  * Gibt die Haeufigkeit von Nichtprimziehungen aller Lottoziehungen auf dem Bildschirm uas.
  */
void Ziehung::schreibe_haeufigkeit_der_nichtprimziehung() const
{
  int anzahl = 0;
  for(unsigned int i = 0; i < lottospiele.size(); i++)
    if(lottospiele[i].pruefe_auf_nichtprimziehung() == true)
      anzahl++;
  double prozent = (double)(anzahl * 100) / (double)(lottospiele.size());
  cout << "\n\nBei " << anzahl << " von " << lottospiele.size() << " Lottospielen handelte es sich um eine Nicht-Primziehung.\n";
  cout << "Das entspricht: " << fixed << setprecision(4) << prozent << " %\n";
}

/**
  * Gibt tabellarisch die Haeufigkeit von k-Ziehungen auf dem Bildschirm aus.
  */
void Ziehung::schreibe_haeufigkeit_k_ziehung()
{
  int array[] = {0, 0, 0, 0, 0, 0, 0};
  for(unsigned int k = 0; k < lottospiele.size(); k++)
  {
    int s = lottospiele[k].liefere_anzahl_aufeinanderfolgende_zahlen();
    array[s - 1] += 1;
  }
  cout << "_____________________\n";
  cout << "| k-ling | Vorkommen |\n";
  cout << "_____________________\n";
  for(int i = 0; i < 6; i++)
  {
    double x = (double)(array[i] * 100) / (double)lottospiele.size();
    cout << "|" << right << fixed << setw(8) << i + 1 << "|";
    cout << right << fixed << setw(11) << array[i] << "|  ";
    cout << fixed << setprecision(4) << x << " %\n";
    cout << "_____________________\n";
  } 
}

/**
  * Erfasst ueber die Eingabe mit der Tastatur einen Lotto-Tipp und vergleicht diesen 
  * mit allen Ziehungen. Auf dem Bildschirm wird dann tabellarisch ausgegeben,
  * wie oft und wieviele Treffer erreicht worden sind.  
  */
void Ziehung::vergleiche_tipp_mit_lottozahlen() const
{
  cout << "\nBitte geben Sie nun Ihren Tipp an:\n";
  Lotto tipp = Lotto(erfasse_lotto_tipp());
  int array[] = {0, 0, 0, 0, 0, 0, 0};
  for(unsigned int i = 0; i < lottospiele.size(); i++)
  {
    int y = lottospiele[i].pruefe_anzahl_richtige_treffer(tipp);
    array[y] += 1;
  }
  cout << "\n_____________________\n";
  cout << "|Richtige| Vorkommen |\n";
  cout << "_____________________\n";
  for(int i = 0; i < 7; i++)
  {
    double x = (double)(array[i] * 100) / (double)lottospiele.size();
    cout << "|" << right << fixed << setw(8) << i << "|";
    cout << right << fixed << setw(11) << array[i] << "|  ";
    cout << fixed << setprecision(4) << x << " %\n";
    cout << "_____________________\n";
  }
}

/**
  * Erstellt so lange neue Lottotipps, bis der Tipp mit den sechs richtigen Zahlen der
  * Lottoziehungen uebereinstimmt.
  */

void Ziehung::erzwinge_treffer() const
{
  int richtige = 0;
  int versuche = 0;
  while(richtige != 6)
  {
    versuche++;
    Lotto x = Lotto();
    for(unsigned int i = 0; i < lottospiele.size(); i++)
    {
      richtige = lottospiele[i].pruefe_anzahl_richtige_treffer(x);
      if(richtige == 6)
        i = lottospiele.size();
    }
  }
  cout << "\n\nEs wurden " << versuche << " Versuche gebraucht um sechs richtige Treffer zu erreichen.\n\n";
}

/**
  * Gibt ein Array tabellarisch auf den Bildschirm aus.
  * @param array Ein Zeiger auf ein Int-Array.
  * @param arraylaenge Die Laenge des Arrays.
  */
void Ziehung::schreibe_array_als_tabelle(int* array, int arraylaenge) const
{
  cout << "_____________________\n";
  cout << "|   Zahl | Vorkommen |\n";
  cout << "_____________________\n";
  for(int i = 0; i < arraylaenge; i++)
  {
    array++;
    if(i == 0)
      array--;
    cout << "|" << right << fixed << setw(8) << i + 1 << "|";
    cout << right << fixed << setw(11) << *array << "|\n";
    cout << "_____________________\n";
  }
}
  
/**
  * Schreibt ein Array tabellarisch auf den Bildschirm inklusive den Werten als Prozentsatz.
  * @param array Ein Zeiger auf ein Int-Array.
  * @param arraylaenge Die Laenge des Arrays.
  */
void Ziehung::schreibe_array_als_tabelle_plus_prozent(int* array, int arraylaenge) const
{
  cout << "_____________________\n";
  cout << "|   Zahl | Vorkommen |\n";
  cout << "_____________________\n";
  for(int i = 0; i < arraylaenge; i++)
  {
    array++;
    if(i == 0)
      array--;
    double x = (double)(*array * 100) / (double)lottospiele.size();
    cout << "|" << right << fixed << setw(8) << i + 5 << "|";
    cout << right << fixed << setw(11) << *array << "|  ";
    cout << fixed << setprecision(4) << x << " %\n";
    cout << "_____________________\n";
  } 
}

/**
  * Liefert die Position in einem Vector mit dem hoechsten Wert.
  * @param ein_vector Ein Int-Vector.
  * @return Die Position im Vektor mit dem hoechsten Wert.
  */
int Ziehung::finde_hoechsten_wert_im_Vector(vector<int> ein_vector) const
{
  int pos = 0;
  int wert = ein_vector[0];
  for(unsigned int i = 1; i < ein_vector.size(); i++)
  {
    if(wert < ein_vector[i])
    {
      wert = ein_vector[i];
      pos = i;
    }
  }
  return pos;
}

/**
  * Liefert die Position in einem Vector mit dem niedrigsten Wert.
  * @param ein_vector Ein Int-Vector.
  * @return Die Position im Vektor mit dem niedrigsten Wert.
  */
int Ziehung::finde_kleinesten_wert_im_Vector(vector<int> ein_vector) const
{
  int pos = 0;
  int wert = ein_vector[0];
  for(unsigned int i = 1; i < ein_vector.size(); i++)
  {
    if(wert > ein_vector[i])
    {
      wert = ein_vector[i];
      pos = i;
    }
  }
  return pos;
}
