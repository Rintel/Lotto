#include <cstdlib>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

#include "Lotto.h"

using namespace std;

/**
  * Erstellt ein Objekt vom Typ Lotto mit 6 zufaelligen Zahlen.
  */
Lotto::Lotto()
{
  liefere_zufaellige_ziehung();
}

/**
  * Erstellt ein Objekt vom Typ Lotto mit Hilfe der Angabe von
  * 6 unterschiedlichen Zahlen aus dem Bereich von 1 bis 49.
  * Wenn die angegebenen Zahlen die Kriterien nicht erfuellen, dann
  * wird ein Fehlertext ausgegeben und durch Zufallszahlen ersetzt. 
  * @param zahlen 6 unterschiedliche Zahlen aus dem Bereich von 1 bis 49.
  */
Lotto::Lotto(vector<int> zahlen)
{
  if (zahlen.size() < 6)
  {
    cout << "\nIhre uebergebenen Zahlen sind unzulaessig.\nSie wurden mit Zufallszahlen ausgetauscht.";
	liefere_zufaellige_ziehung();
  }
  else
    lottozahlen = zahlen;
}

/**
  * Gibt die Lottozahlen auf dem Bildschirm aus.
  */
void Lotto::schreibe_zahlen()
{
  for(unsigned int i = 0; i < lottozahlen.size(); i++)
    cout << lottozahlen[i] << "\n";
}

/**
  * Liefert die Lottozahlen als Vektor.
  * @return Die Lottozahlen.
  */
vector<int> Lotto::liefere_lottozahlen() const
{
  return lottozahlen;
}

/**
  * Liefert die Anzahl der Primzahlen aus der Lottoziehung.
  * @return Die Anzahl der vorkommenden Primzahlen.
  */
int Lotto::liefere_anzahl_primzahlen() const
{
  int array[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
  int anzahl = 0;
  for(unsigned int i = 0; i < lottozahlen.size(); i++)
  {
    for(unsigned int k = 0; k < 15; k++)
    {
      if (lottozahlen[i] == array[k])
        anzahl++;
    }
  }
  return anzahl;
}

/**
  * Liefert die niedrigste Zahl der Lottoziehung.
  * @return Die niedrigste Zahl der Lottoziehung.
  */
int Lotto::liefere_kleinste_zahl() const
{
  int kleinste = lottozahlen[0];
  for(unsigned int i = 1; i < lottozahlen.size(); i++)
  {
    if (lottozahlen[i] < kleinste)
      kleinste = lottozahlen[i];
  }
  return kleinste;
}

/**
  * Liefert die hoechste Zahl der Lottoziehung.
  * @return Die hoechste Zahl der Lottoziehung.
  */
int Lotto::liefere_groesste_zahl() const
{
  int groesste = lottozahlen[0];
  for(unsigned int i = 1; i < lottozahlen.size(); i++)
  {
    if (lottozahlen[i] > groesste)
      groesste = lottozahlen[i];
  }
  return groesste;
}

/**
  * Liefert die Differenz zwischen der niedrigsten und der hoechsten Zahl der Lottoziehung.
  * @return Die Differenz.
  */
int Lotto::liefere_differenz() const
{
  int kleinste = liefere_kleinste_zahl();
  int groesste = liefere_groesste_zahl();
  return (groesste - kleinste);
}

/**
  * Ueberprueft ob es sich bei der Lottoziehung um eine gerade Ziehung handelt.
  * @return Wird true wenn es sich um eine gerade Ziehung handelt, wenn nicht false.
  */
bool Lotto::pruefe_auf_gerade_ziehung() const
{
  bool gerade_ziehung = false;
  int x = liefere_anzahl_gerader_zahlen();
  if (x == 6)
    gerade_ziehung = true;
  return gerade_ziehung;
}

/**
  * Vergleicht 2 Lottoziehungen miteinander und ermittelt,
  *s wieviele Zahlen uebereinstimmen innerhalb der Ziehungen uebereinstimmen.
  * @return Anzahl der Treffer.
  */
int Lotto::pruefe_anzahl_richtige_treffer(Lotto lotto_tipp) const
{
  vector<int> x = lotto_tipp.liefere_lottozahlen();
  int anzahl = 0;
  for(unsigned int i = 0; i < lottozahlen.size(); i++)
  {
    for(unsigned int k = 0; k < x.size(); k++)
    {
      if (lottozahlen[i] == x[k])
        anzahl++;
    }
  }
  return anzahl;
}

/**
  * Ueberprueft ob es sich bei der Lottoziehung um eine UNGERADE Ziehung handelt.
  * (Alle Zahlen sind ungerade)
  * @return Wird true wenn es sich um eine ungerade Ziehung handelt, wenn nicht false.
  */
bool Lotto::pruefe_auf_ungerade_ziehung() const
{
  bool ungerade_ziehung = false;
  int x = liefere_anzahl_gerader_zahlen();
  if (x == 0)
    ungerade_ziehung = true;
  return ungerade_ziehung;
}

/**
  * Ueberprueft ob es sich bei der Lottoziehung um eine Primziehung handelt.
  * (Alle Zahlen sind Primzahlen)
  * @return Wird true wenn es sich um eine Primziehung handelt, wenn nicht False.
  */
bool Lotto::pruefe_auf_primziehung() const
{
  bool prim_ziehung = false;
  int x = liefere_anzahl_primzahlen();
  if (x == 6)
    prim_ziehung = true;
  return prim_ziehung;
}

/**
  * Ueberprueft ob es sich bei der Lottoziehung um eine Nichtprimziehung handelt
  *  d.h es kommen keine Primzahlen in der Ziehnung vor.
  * @return true wenn es sich um eine Nichtprimziehung handelt, wenn nicht false.
  */
bool Lotto::pruefe_auf_nichtprimziehung() const
{
  bool nichtprim_ziehung = false;
  int x = liefere_anzahl_primzahlen();
  if (x == 0)
    nichtprim_ziehung = true;
  return nichtprim_ziehung;
}

/**
  * Ueberprueft ob die Laenge der Ziehung (Differenz zwischen kleinster und groesster Zahl)
  * als Zahl in der Lottoziehung vorkommt.
  * @return True wenn sie vorkommt, wenn nicht False.
  */
bool Lotto::pruefe_ob_differenz_vorhanden() const
{
  bool x = false;
  int laenge = liefere_differenz();
  for(unsigned int i = 0; i < lottozahlen.size(); i++)
    if (laenge == lottozahlen[i])
      x = true;
  return x;
}

/**
  * Liefert die Anzahl der aufeinanderfolgenden Zahlen der Lottoziehung.
  * @return Liefert den Wert um welche Ziehung es sich handelt.
  */
int Lotto::liefere_anzahl_aufeinanderfolgende_zahlen()
{
  int zwsp2 = 1;
  int zwsp = 1;
  for(unsigned int i = 0; i < lottozahlen.size(); i++)
  {
    zwsp2 = 1;
    for(unsigned int k = i; k < lottozahlen.size(); k++)
    {
      if ((lottozahlen[k] + 1) == lottozahlen[k + 1])
      {
        zwsp2++;
        if(zwsp < zwsp2)
          zwsp = zwsp2;
      }
      else
        zwsp2 = 1;
    }
  }
  return zwsp;
}

/**
  * Liefert die Anzahl der geraden Zahlen der Lottoziehung.
  * @return Die Anzahl der geraden Zahlen der Lottoziehung.
  */
int Lotto::liefere_anzahl_gerader_zahlen() const
{
  int anzahl = 0;
  for(unsigned int i = 0; i < lottozahlen.size(); i++)
  {
    if ((lottozahlen[i] % 2) == 0)
      anzahl++;
  }
  return anzahl;
}

/**
  * Sortiert die Lottozahen aufsteigend nach der Groesse.
  */
void Lotto::sortiere_aufsteigend()
{
  int tmp;
  for (unsigned int i = 0; i < lottozahlen.size() - 1; ++i) 
  { 
    for (unsigned int j = 0; j < lottozahlen.size() - i - 1; ++j) 
    {
      if (lottozahlen[j] > lottozahlen[j + 1]) 
      {
        tmp = lottozahlen[j];
        lottozahlen[j] = lottozahlen[j + 1];
        lottozahlen[j + 1] = tmp;
      }
    }
  }
}

/**
  * Liefert eine zufaellige Lottoziehung.
  */
void Lotto::liefere_zufaellige_ziehung()
{
  vector<int> ziehung;
  for (int i = 1; i < 50; i++)
    ziehung.push_back(i);
  random_shuffle(ziehung.begin(), ziehung.end());
  for(int q = 1; q < 7; q++)
    lottozahlen.push_back(ziehung[q]); 
}
