#ifndef ELABORATO_CONTO_H
#define ELABORATO_CONTO_H


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

        bool aggiungiTransazione(const Transazione& t);

        void stampaTransazioni() const;

        void aggiornamentoIniziale();

        void scaricaTransazione(const Transazione &t);
};


#endif //PROGETTO_CONTO_H