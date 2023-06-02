#include "Transazione.h"
#include "Data.h"

Transazione::Transazione() {
    setImporto(0);
}

Transazione::Transazione(bool tipo, const std::string &descrizione, float importo, Data data) {
    if(importo<0)
        throw std::invalid_argument("Non e' stato possibile creare la transazione, in quanto l'importo inserito era negativo, si prega di inserirne un altro!");
    else
        Transazione::tipo=tipo;
        Transazione::importo=importo;
        Transazione::descrizione=descrizione;
        Transazione::data=data;
}

bool Transazione::getTipo() const {
    return tipo;
}

void Transazione::setTipo(bool tipo) {
    Transazione::tipo = tipo;
}

const std::string &Transazione::getDescrizione() const {
    return descrizione;
}

void Transazione::setDescrizione(const std::string &descrizione) {
    Transazione::descrizione = descrizione;
}

float Transazione::getImporto() const {
    return importo;
}

bool Transazione::setImporto(float importo) {
    if(importo >= 0){
        Transazione::importo = importo;         //le transazioni devono tutte avere importo uguale o superiore a 0
        return true;
    }
    else return false;
}

const Data &Transazione::getData() const {
    return data;
}

void Transazione::setData(const Data &data) {
    Transazione::data = data;
}
