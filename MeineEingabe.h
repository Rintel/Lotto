#ifndef MEINEEINGABE_H
#define	MEINEEINGABE_H

#include <vector>

using namespace std;

double erfasse_double(double min, double max);
void erfasse_zeichenkette(std::string& eingabe);
long erfasse_long(long min, long max);
int erfasse_int(int min, int max);
void nachkommastellen_abschneiden(double& wert, size_t stelle);
vector<int> erfasse_lotto_tipp();

#endif	/* MEINEEINGABE_H */

