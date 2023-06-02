#ifndef ELABORATO_CONTO_H
#define ELABORATO_CONTO_H


#include "Transazione.h"
#include <list>

class Conto {
    private:

        std::string nome;
        float saldo;
        std::list<Transazione> listaTransazioni;

    public:
        Conto();

        Conto(const std::string &nome, float saldo);

        float getSaldo() const;

        bool aggiungiTransazione(const Transazione &t, const std::string &path);

        void stampaTransazioni() const;

        void aggiornamentoIniziale(const std::string &path);

        void leggiTransazione(const Transazione &t);

        void modificaTransazione(const std::string &path);

        void cancellaTransazione(const std::string &path);

        void riscriviFile(const std::string &path);

};


#endif //PROGETTO_CONTO_H