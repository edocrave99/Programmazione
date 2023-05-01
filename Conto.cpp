#include "Conto.h"
#include "Transazione.h"
#include <iostream>
#include <fstream>

using namespace std;

Conto::Conto() {
    setSaldo(0);
}

Conto::Conto(float saldo) : saldo(saldo) {}

float Conto::getSaldo() const {
    return saldo;
}

void Conto::setSaldo(float saldo) {
    Conto::saldo=saldo;
}

bool Conto::aggiungiTransazione(const Transazione &t) {
    bool r=true;
    if(t.getTipo()==0)
        if(t.getImporto()>saldo)
            r=false;
        else {
            listaTransazioni.push_back(t);
            saldo-=t.getImporto();
        }
    else {
        listaTransazioni.push_back(t);
        saldo+=t.getImporto();
    }
    return r;
}

void Conto::stampaTransazioni() const {
    cout << "TRANSAZIONI:" << endl;
    cout<< endl;

    for (const auto& t : listaTransazioni) {
        cout << "Tipo: ";
        auto tipo = t.getTipo();
        if (tipo == true)
            cout << "In ingresso" << endl;
        else cout << "In uscita" << endl;
        cout << "Importo: ";
        cout << t.getImporto() << endl;
        cout << "Data: ";
        auto d = t.getData();
        d.stampaData();
        cout << endl;
        cout << "Descrizione: ";
        cout << t.getDescrizione() << endl;
        cout << endl;
    }
}