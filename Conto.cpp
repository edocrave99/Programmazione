//
// Created by zcrav on 14/03/2023.
//

#include "Conto.h"
#include <iostream>
#include <stdio.h>
using namespace std;

float Conto::getSaldo() const {
    return saldo;
}

void Conto::setSaldo(float saldo) {
    this->saldo=saldo;
}

void Conto::transazioneIngresso(int x) {
    saldo += x;
}
void Conto::transazioneUscita(int x) {
    if(saldo<x){
        cout << "Non e' possibile effettuare la seguente operazione, in quanto il saldo attuale non e' sufficiente" <<endl;
    }
    else saldo -= x;
}

Conto::Conto() {

}

Conto::Conto(float saldo) {
    this->saldo=saldo;
}
