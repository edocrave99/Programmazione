#include "Transazione.h"
#include "Data.h"

Transazione::Transazione() {
    setImporto(0);
}

Transazione::Transazione(bool tipo, const std::string &descrizione, float importo) : tipo(tipo),
                                                                                     descrizione(descrizione),
                                                                                     importo(importo) {}

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

void Transazione::setImporto(float importo) {
    Transazione::importo = importo;
}

const Data &Transazione::getData() const {
    return data;
}

void Transazione::setData(const Data &data) {
    Transazione::data = data;
}
