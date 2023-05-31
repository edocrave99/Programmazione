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
    bool f= isValid(giorno, mese, anno);
    if (f==false)
        throw invalid_argument("Non e' stato possibile inserire la data, in quanto quella inserita non era valida, si prega di inserirne un altra!");
    Data::giorno = giorno;
    Data::mese = mese;
    Data::anno = anno;
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
