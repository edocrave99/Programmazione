#include <iostream>
#include <stdio.h>
#include "Conto.h"
#include "Transazione.h"
#include <string>

using namespace std;

// Classi che rappresentano transazioni finanziarie su un conto corrente (ingresso e uscita).
// Le classi devono essere in gradi leggere e salvare i dati su file.

int main() {
    Conto c(5000);
    int selettore1, selettore2, v;
    float s;
    std::string d;
    bool f = false;
    cout << "Benvenuto sul gestore di transazione finanziarie di Cravegni Edoardo" << endl;

    while (f == false) {
        cout << "Ecco le operazioni che posso effettuare:" << endl;
        cout << "1) Visualizza il tuo saldo" << endl;
        cout << "2) Effettua una transazione" << endl;
        cout << "3) Visualizza il tuo storico delle transazioni" << endl;
        cout << "0) Uscire" << endl;
        cout << "Inserire il numero corrispondente all'operazione che si desidera effettuare: " << endl;
        cin >> selettore1;

        switch (selettore1) {
            case 1:
                s = c.getSaldo();
                cout << "Il saldo attuale e': " << s << endl;
                break;
            case 2:
                cout << "Che tipo di transazione desidera effettuare" << endl;
                cout << "1) In ingresso" << endl;
                cout << "2) In uscita" << endl;
                cout << "0) Torna indietro" << endl;
                cin >> selettore2;
                switch (selettore2) {
                    case 1:
                        cout << "Inserire il valore da aggiungere al saldo: ";
                        cin >> v;
                        cout << "Inserire una descrizione per la nuova transazione: ";
                        cin >> d;
                        Transazione t1(true, d, v);
                        c.aggiungiTransazione(t1);
                        break;
                    //**************************************************
                }
                break;
            case 3:
                c.stampaTransazioni();
                break;
            case 0:
                f = true;
                break;
            default:
                cout << "Il numero inserito non corrisponde a nessuna operazione" << endl;
                break;
        }
    }
    return 0;
}
