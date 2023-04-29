//
// Created by zcrav on 14/03/2023.
//

#include "Conto.h"
#include "Transazione.h"
#include <iostream>
#include <fstream>
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
            cout << "Non e' stato possibile eseguire la transazione desiderata in quanto il saldo attuale non e' sufficiente" << endl;
        else {
            listaTransazioni.push_back(t);
            saldo-=t.getImporto();
        }
    else {
        listaTransazioni.push_back(t);
        saldo+=t.getImporto();
    }
}

void Conto::stampaTransazioni() const {
    std::cout << "Transazioni:" << std::endl;
    for (const auto& t : listaTransazioni) {
        cout << "Tipo: ";
        auto tipo = t.getTipo();
        if (tipo== true)
            cout << "In ingresso" <<endl;
        else cout << "In uscita" <<endl;
        cout << "Importo: ";
        cout << t.getImporto() << endl;
        cout << "Data: ";
        auto d=t.getData();
        cout << endl;
        d.stampaData();
        cout << endl;
        cout << "Descrizione: ";
        cout << t.getDescrizione() << endl;
    }
}