#include <iostream>
#include <climits>
#include <cfloat>
#include <cmath>
#include <vector>

#include "MeineEingabe.h"


using namespace std;

/**
  * Diese Funktion erfasst einen Wert vom Typ double aus dem Bereich von min bis max.
  * 
  * @param min Der kleinst moegliche Wert. 
  * @param max Der groesst moegliche Wert.
  * @return Der erfasste Wert aus dem Bereich von min bis max.
  */
double erfasse_double(double min, double max)
{
  if (max < min)
  {
      double zwsp = min;
      min = max;
      max = zwsp;
  }
  double eingabe = 0;
  bool eingabe_ok = false;
  cin.clear();
  cin.unsetf(cin.skipws);
  do
  {
    cin >> eingabe;
    eingabe_ok = cin.good() && min <= eingabe && eingabe <= max;
    cin.clear();
    cin.ignore(static_cast<streamsize>(DBL_MAX), '\n');
    if (!eingabe_ok)
    {
      cout << "Bitte eine Zahl eingeben [";
      cout << min << " - " << max << "]: ";
    }
  } while (!eingabe_ok);
  cin.setf(cin.skipws);
  return eingabe;
}

/**
  * Diese Funktion erfasst einen Wert vom Typ long aus dem Bereich von min bis max.
  * 
  * @param min Der kleinst moegliche Wert. 
  * @param max Der groesst moegliche Wert.
  * @return Der erfasste Wert aus dem Bereich von min bis max.
  */
long erfasse_long(long min, long max)
{
  if (max < min)
  {
      long zwsp = min;
      min = max;
      max = zwsp;
  }
  long eingabe = 0;
  bool eingabe_ok = false;
  cin.clear();
  cin.unsetf(cin.skipws);
  do
  {
    cin >> eingabe;
    eingabe_ok = cin.good() && min <= eingabe && eingabe <= max;
    cin.clear();
    cin.ignore(static_cast<streamsize>(LONG_MAX), '\n');
    if (!eingabe_ok)
    {
      cout << "Bitte eine ganze Zahl eingeben [";
      cout << min << " - " << max << "]: ";
    }
  } while (!eingabe_ok);
  cin.setf(cin.skipws);
  return eingabe;
}

/**
  * Erfasst einen Wert vom Typ int aus dem Bereich von min bis max.
  *
  * @param min Der kleinst moegliche Wert.
  * @param max Der groesst moegliche Wert.
  * @return Der erfasste Wert aus dem Bereich von min bis max.
  */
int erfasse_int(int min, int max)
{
  return static_cast<int>(erfasse_long(min, max));
}


/**
 * Erfasst eine Zeichenkette.
 * @param eingabe Einen String.
 */
void erfasse_zeichenkette(string& eingabe)
{
  cin >> eingabe;
  cin.ignore(static_cast<streamsize>(LONG_MAX), '\n');
}

/**
 * Schneidet Stellen einer Gleitkommazahl an einer bestimmten Teil ab.
 * (positiv = Nachkommastellen | negativ = Vorkommasellen)
 * @param wert Die Gleitkommazahl.
 * @param stelle Die Stelle an der getrennt werden soll.
 */
void nachkommastellen_abschneiden(double& wert, size_t stelle) 
{
  double powsum = pow(10.0, (double)stelle);
  wert = int(powsum * wert);
  wert /= powsum;
}

/**
  * Erfasst 6 verschiedene Zahlen aus dem ereich von 1 bis 49.
  * @return 6 verschiedene Zahlen aus dem ereich von 1 bis 49.
  */
vector<int> erfasse_lotto_tipp()
{
  vector<int> eingaben;
  cout << "\nBitte geben Sie Ihre 1. Zahl an: ";
  int eing = erfasse_int(1,49);
  eingaben.push_back(eing);
  int z = 1;
  while(z != 6)
  {
    z++;
    bool ok = true;
    do
    {
      ok = true;
      cout << "\nBitte geben Sie eine weitere Zahl an: ";
      eing = erfasse_int(1,49);
      for(unsigned int i = 0; i < eingaben.size(); i++)
      {
        if(eing == eingaben[i])
        {
          i = 10;
          cout << "\nDiese Zahl ist bereits vorhanden.\n";
          ok = false;
        }
      }
    }while(!ok);
    eingaben.push_back(eing);
  }
  return eingaben;
}
