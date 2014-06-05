#ifndef ZIEHUNG_H
#define	ZIEHUNG_H

#include "Lotto.h"
#include <vector>

using namespace std;

class Ziehung
{
private:
    /**Anzahl der gewuenschten Lottoziehungen*/
    vector<Lotto> lottospiele;
    
public:
    Ziehung();
    Ziehung(int anzahl_der_spiele);
    
    void anzahl_spiele_in_jahre() const;
    void schreibe_haeufigkeitsverteilung() const;
    void schreibe_minimumverteilung() const;
    void schreibe_maximaverteilung() const;
    void schreibe_laengenverteilung() const;
    void schreibe_laenge_als_zahl_haeufigkeit() const;
    void schreibe_haeufigkeit_der_geraden_ziehungen() const;
    void schreibe_haeufigkeit_der_ungeraden_ziehungen() const;
    void schreibe_haeufigkeit_der_primziehungen() const;
    void schreibe_haeufigkeit_der_nichtprimziehung() const;
    void schreibe_haeufigkeit_k_ziehung();
    void vergleiche_tipp_mit_lottozahlen() const;
    void erzwinge_treffer() const;
    void schreibe_auftreten_der_laenge_als_zahl() const;
    
private:
    void schreibe_array_als_tabelle(int* array, int arraylaenge) const;
    void schreibe_array_als_tabelle_plus_prozent(int* array, int arraylaenge) const;
    int finde_kleinesten_wert_im_Vector(vector<int> ein_vector) const;
    int finde_hoechsten_wert_im_Vector(vector<int> ein_vector) const;
};

#endif	/* ZIEHUNG_H */

