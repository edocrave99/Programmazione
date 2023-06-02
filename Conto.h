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

        Conto(std::string nome, float saldo);

        float getSaldo() const;

        bool setSaldo(float saldo);

        bool aggiungiTransazione(const Transazione &t, std::string path);

        void stampaTransazioni() const;

        void aggiornamentoIniziale(std::string path);

        void leggiTransazione(const Transazione &t);

        void modificaTransazione(std::string path);

        void cancellaTransazione(std::string path);

        void riscriviFile(std::string path);

};


#endif //PROGETTO_CONTO_H