#include <iostream>
#include <stdio.h>
#include "conto.h"

using namespace std;

// Classi che rappresentano transazioni finanziarie su un conto corrente (ingresso e uscita).
// Le classi devono essere in gradi leggere e salvare i dati su file.

int main() {
    Conto *c= new Conto(5000);
    int selettore1, selettore2, x;
    float s;
    cout << "Benvenuto sul gestore di transazione finanziarie di Cravegni Edoardo" << endl;
    cout << "Ecco le operazioni che posso effettuare:" << endl;
    cout << "1) Visualizza il tuo saldo" << endl;
    cout << "2) Effettua una transazione" << endl;
    cout << "0) Uscire" << endl;
    cout << "Inserire il numero corrispondente all'operazione che si desidera effettuare" << endl;
    cin >> selettore1;

    switch (selettore1){
        case 1:
            s= c->getSaldo();
            cout << "Il saldo attuale e': "<< s;
            break;
        case 2:
            cout << "2Che tipo di transazione desidera effettuare" << endl;
            cout << "1) In ingresso" << endl;
            cout << "2) In uscita" << endl;
            cout << "0) Ho cambiato idea" <<  endl;
            cin >> selettore2;
            switch (selettore2){
                case 1:
                    cout << "Inserire il valore da aggiungere al saldo: ";
                    cin >> x;
                    c->transazioneIngresso(x);
                    break;
                case 2:
                    cout << "Inserire il valore che desidera prelevare: ";
                    cin >> x;
                    c->transazioneUscita(x);
                    break;
                case 0:
                    break;
                default:
                    cout << "Il numero inserito non corrisponde a nessuna operazione" << endl;
                    break;
            }
        case 0:
            break;
        default:
            cout << "Il numero inserito non corrisponde a nessuna operazione" << endl;
            break;
    }
}
