//
// Created by zcrav on 14/03/2023.
//

#ifndef PROGETTO_CONTO_H
#define PROGETTO_CONTO_H


class Conto {
private:
    float saldo;

public:
    Conto();
    Conto(float saldo);
    float getSaldo() const;
    void setSaldo(float saldo);
    void transazioneIngresso(int x);
    void transazioneUscita(int x);
};


#endif //PROGETTO_CONTO_H