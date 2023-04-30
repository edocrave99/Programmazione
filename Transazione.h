#ifndef ELABORATO_TRANSAZIONE_H
#define ELABORATO_TRANSAZIONE_H

#include <string>
#include "Data.h"

class Transazione {
    private:
        bool tipo;
        std::string descrizione;
        float importo;
        Data data;

    public:

        Transazione();

        Transazione(bool tipo, const std::string &descrizione, float importo);

        bool getTipo() const;

        void setTipo(bool tipo);

        const std::string &getDescrizione() const;

        void setDescrizione(const std::string &descrizione);

        float getImporto() const;

        void setImporto(float importo);

        const Data &getData() const;

        void setData(const Data &data);
};


#endif //ELABORATO_TRANSAZIONE_H
