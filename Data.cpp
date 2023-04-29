//
// Created by zcrav on 15/03/2023.
//

#include "Data.h"
#include <iostream>

using namespace std;

Data::Data() {}

Data::Data(int giorno, int mese, int anno) : giorno(giorno), mese(mese), anno(anno) {}

int Data::getGiorno() const {
    return giorno;
}

void Data::setGiorno(int giorno) {
    Data::giorno = giorno;
}

int Data::getMese() const {
    return mese;
}

void Data::setMese(int mese) {
    Data::mese = mese;
}

int Data::getAnno() const {
    return anno;
}

void Data::setAnno(int anno) {
    Data::anno = anno;
}

void Data::stampaData() const {
    int g, m, a;
    g=getGiorno();
    m=getMese();
    a=getAnno();
    cout << g;
    cout << "/";
    cout << m;
    cout << "/";
    cout << a;
}

bool Data::isValid() const {
        int m,g,a;
        m=getMese();
        g=getGiorno();
        a=getAnno();
        if (m < 1 || m > 12 || g < 1) return false;
        int giorni_del_mese = giorniInMese(m, a);
        if (g <= giorni_del_mese)
            return true;
        else return false;
}
