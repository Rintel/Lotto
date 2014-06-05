/* 
 * File:   lotto_main.cpp
 * Author: Cedric Laier
 *
 * Created on 2. Januar 2014, 12:33
 */
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <vector>
#include <ctime>
#include "Lotto.h"
#include "Ziehung.h"
#include "MeineEingabe.h"

using namespace std;

bool ueberpruefe_parameter(int argc, char** argv);
void schreibe_menue();
/**
 *  Dieses Programm ermoeglicht es dem Nutzer zufaellige Lottoziehnungen statistisch auszuwerden.
 *  Dabei hat er die Moeglichkeit die Anzahl der Ziehungen festzulegen. Dieses geschieht ueber 
 *  eine Parameter Uebergabe. Nachdem die Zahlen erstellt worden sind, hat der Nutzer 
 *  verschiedene Moeglichkeiten ueber ein Menue die Ziehungen auszuwerten.
 *  Der Nutzer kann sich eine Anzahl von Ziehungen im Bereich 2 - 4.000.000 bestimmen.
 */
int main(int argc, char** argv) 
{
  srand((unsigned)time(NULL));
  if(ueberpruefe_parameter(argc, argv))
  {
    int eingabe = atof(argv[1]);
    int auswahl = 0;
    Ziehung liste = Ziehung(eingabe);
    cout << "\n\nNeue Liste wurde erstellt!\n\n";
    while(auswahl != 15)
    {
      schreibe_menue();
      auswahl = erfasse_int(1,15);
      if(auswahl == 1)
        liste.anzahl_spiele_in_jahre();
      else if(auswahl == 2)
        liste.schreibe_haeufigkeitsverteilung();
      else if(auswahl == 3)
        liste.schreibe_minimumverteilung();
      else if(auswahl == 4)
        liste.schreibe_maximaverteilung();
      else if(auswahl == 5)
        liste.schreibe_laengenverteilung();
      else if(auswahl == 6)
        liste.schreibe_auftreten_der_laenge_als_zahl();
      else if(auswahl == 7)
        liste.schreibe_haeufigkeit_der_geraden_ziehungen();
      else if(auswahl == 8)
        liste.schreibe_haeufigkeit_der_ungeraden_ziehungen();
      else if(auswahl == 9)
        liste.schreibe_haeufigkeit_der_primziehungen();
      else if(auswahl == 10)
        liste.schreibe_haeufigkeit_der_nichtprimziehung();
      else if(auswahl == 11)
        liste.schreibe_haeufigkeit_k_ziehung();
      else if(auswahl == 12)
        liste.vergleiche_tipp_mit_lottozahlen();
      else if(auswahl == 13)
        liste.erzwinge_treffer();
      else if(auswahl == 14)
      {
        cout << "\nBitte geben Sie einen neuen Wert an[1 - 10000000]: ";
        eingabe = erfasse_int(1, 10000000);
        liste = Ziehung(eingabe);
        cout << "\n\nNeue Liste wurde erstellt!\n\n";
      }
    }
  }
}

/**
 * Ueberprueft die Programmparameter auf Fehleingaben.
 * @param argc Die Anzahl der Programmparameter.
 * @param argv Die Programmparameter.
 * @return True wenn alles korrekt, false wenn nicht.
 */
bool ueberpruefe_parameter(int argc, char* argv[])
{
  bool parameter_ok = true;
  if (argc < 2)
    parameter_ok = false;
  else if (atof(argv[1]) < 1 || atof(argv[1]) > 4000000)
    parameter_ok = false;
  if (parameter_ok == false)
    cout << "\n\nDas Programmaufruf: [Programmname] n\n1 < n < 4.000.000\n\n";
  return parameter_ok;	
}

/**
 * Schreibt das Auswahlmenue fuer den Benutzer auf den Bildschirm.
 */
void schreibe_menue()
{
  cout << "\n\nBitte waehlen:\n\n";
  cout << "(1)  Information\n";
  cout << "(2)  Haeufigkeitsverteilung\n";
  cout << "(3)  Verteilung der Minima\n";
  cout << "(4)  Verteilung der Maxima\n";
  cout << "(5)  Verteilung der Ziehungslaengen\n";
  cout << "(6)  Anzahl Ziehungen, die ihre Laenge enthalten\n";
  cout << "(7)  Anzahl gerade Ziehungen\n";
  cout << "(8)  Anzahl ungerade Ziehungen\n";
  cout << "(9)  Anzahl Primziehungen\n";
  cout << "(10) Anzahl Nichtprimziehungen\n";
  cout << "(11) Verteilung der k-Ziehungen\n";
  cout << "(12) Tippen\n";
  cout << "(13) Automatisch Tippen\n";
  cout << "(14) Neue Ziehungen\n";
  cout << "(15) Beenden\n\n";
  cout << "Ihre Auswahl: ";
}

