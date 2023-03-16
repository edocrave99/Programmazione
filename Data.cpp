//
// Created by zcrav on 15/03/2023.
//

#include "Data.h"
#include <iostream>

using namespace std;

Data::Data() {}

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
