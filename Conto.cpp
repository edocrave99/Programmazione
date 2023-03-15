//
// Created by zcrav on 14/03/2023.
//

#include "Conto.h"
#include <iostream>
#include <list>
using namespace std;

Conto::Conto() {}

Conto::Conto(float saldo) : saldo(saldo) {}

float Conto::getSaldo() const {
    return saldo;
}

void Conto::setSaldo(float saldo) {
    Conto::saldo=saldo;
}

void Conto::aggiungiTransazione(const Transazione &t) {
    if(t.getTipo()==0)
        if(t.getImporto()>saldo)
            cout << "Non e' stato possibile eseguire la transazione desiderata in quanto il saldo attuale non è sufficiente" << endl;
        else {
            cout << "La transazione e' stata eseguita con successo" << endl;
            listaTransazioni.push_back(t);
            saldo-=t.getImporto();
        }
    else {
        cout << "La transazione e' stata eseguita con successo" << endl;
        listaTransazioni.push_back(t);
        saldo+=t.getImporto();
    }
}

void Conto::stampaTransazioni() const {
    std::cout << "Transazioni:" << std::endl;
    for (const auto& t : listaTransazioni) {
        std::cout << t << std::endl;
    }
}
