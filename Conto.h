//
// Created by zcrav on 14/03/2023.
//

#ifndef PROGETTO_CONTO_H
#define PROGETTO_CONTO_H


#include "Transazione.h"
#include <list>

class Conto {
    private:

        float saldo;
        std::list<Transazione> listaTransazioni;

    public:
        Conto();

        explicit Conto(float saldo);

        float getSaldo() const;

        void setSaldo(float saldo);

        void aggiungiTransazione(const Transazione& t);

        void stampaTransazioni() const;
};


#endif //PROGETTO_CONTO_H