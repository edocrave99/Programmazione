#include "Data.h"
#include <iostream>
#include <sstream>

using namespace std;

Data::Data() {
    Data::giorno = 1;
    Data::mese = 1;
    Data::anno = 2000;
}

Data::Data(int giorno, int mese, int anno) {
    int g, m, a;
    g = giorno;
    m = mese;
    a = anno;
    bool f= isValid(g, m, a);
    if (f) {
        Data::giorno = g;
        Data::mese = m;
        Data::anno = a;
    }
    else cout << "Non è stato possibile inserire la data, in quanto quella inserita non era valida";
}

int Data::getGiorno() const {
    return giorno;
}

int Data::getMese() const {
    return mese;
}

int Data::getAnno() const {
    return anno;
}

string Data::toString() const {
    ostringstream s1;
    string s2;
    s1 << getGiorno() << "/" << getMese() << "/" << getAnno();
    s2 = s1.str();
    return s2;
}

bool Data::isValid(int giorno, int mese, int anno) const {
        if (mese < 1 || mese > 12 || giorno < 1) return false;
        int giorni_del_mese = giorniInMese(mese, anno);
        if (giorno <= giorni_del_mese)
            return true;
        else return false;
}
