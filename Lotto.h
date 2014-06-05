#ifndef LOTTO_H
#define	LOTTO_H
#include <vector>

using namespace std;

class Lotto
{
  private:
    /**6 Lottozahlen aus dem Bereich von 1 bis 49.*/
    vector<int> lottozahlen;
    
  public:
    Lotto();
    Lotto(vector<int> zahlen);
    
    vector<int> liefere_lottozahlen() const;
    void schreibe_zahlen();
    int liefere_anzahl_primzahlen() const;
    int liefere_kleinste_zahl() const;
    int liefere_groesste_zahl() const;
    int liefere_differenz() const;
    bool pruefe_auf_gerade_ziehung() const;
    bool pruefe_auf_ungerade_ziehung() const;
    bool pruefe_auf_primziehung() const;
    bool pruefe_auf_nichtprimziehung() const;
    int liefere_anzahl_aufeinanderfolgende_zahlen();
    int pruefe_anzahl_richtige_treffer(Lotto lotto_tipp) const;
    bool pruefe_ob_differenz_vorhanden() const;
    
  private:
    int liefere_anzahl_gerader_zahlen() const;
    void liefere_zufaellige_ziehung();
    void sortiere_aufsteigend();
};

#endif	/* LOTTO_H */

