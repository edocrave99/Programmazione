#include <iostream>
#include <stdio.h>
#include <fstream>
#include "Conto.h"
#include "Transazione.h"
#include <string>

using namespace std;

// Classi che rappresentano transazioni finanziarie su un conto corrente (ingresso e uscita).
// Le classi devono essere in gradi leggere e salvare i dati su file.

int main() {
    ifstream file("C:\\Elaborato\\cmake-build-debug\\Conto.txt");
    ofstream addt;
    Conto c(0);
    auto *t = new Transazione();
    Data *d = new Data();
    int sel1, sel2, v, g, m, a; //le variabili sel1 e sel2 servono per gestire gli switch case, v per inserire il saldo delle nuove transazioni, mentre g,m,a servonjo invece per la data delle eventuali nuove transazioni
    float s;     //variabili usatìe per visualizzare il saldo del conto e per settare il tipo della transazione nel caso se ne voglia aggiungere una nuova
    std::string descrizione;     //variabile per inserire la descrizione di una nuova transazione
    bool f1 = false,type, f2;    //f1 serve per gestire il ciclo all'interno del quale è inserito lo switch, f2  gestisce il ciclo per l'inserimento della data di una transazione, mentre type serve per stabilire il tipo delle transazioni (ingresso o uscita)
    while(file >> type >> v >> descrizione >> g >> m >> a) {
        d->setGiorno(g);
        d->setMese(m);
        d->setAnno(a);
        t->setTipo(type);
        t->setImporto(v);
        t->setDescrizione(descrizione);
        t->setData(*d);
        c.aggiungiTransazione(*t);
    }
    cout << "Benvenuto sul gestore di transazione finanziarie di Cravegni Edoardo" << endl;

    while (!f1) {
        cout << "Ecco le operazioni che posso effettuare:" << endl;
        cout << "1) Visualizza il tuo saldo" << endl;
        cout << "2) Effettua una transazione" << endl;
        cout << "3) Visualizza il tuo storico delle transazioni" << endl;
        cout << "0) Uscire" << endl;
        cout << "Inserire il numero corrispondente all'operazione che si desidera effettuare:" << endl;
        cin >> sel1;

        switch (sel1) {
            case 1:
                s = c.getSaldo();
                cout << "Il saldo attuale e': " << s << endl;
                break;
            case 2:
                addt.open("C:\\Elaborato\\cmake-build-debug\\Conto.txt", std::ios::app);
                cout << "Che tipo di transazione desidera effettuare" << endl;
                cout << "1) In ingresso" << endl;
                cout << "2) In uscita" << endl;
                cout << "0) Torna indietro" << endl;
                cin >> sel2;
                switch (sel2) {
                    case 1:
                        type=true;
                        f2=false;
                        cout << "Inserire il valore da aggiungere al saldo:" << endl;
                        cin >> v;
                        cout << "Inserire una descrizione per la nuova transazione:" << endl;
                        cin >> descrizione;
                        while(!f2) {
                            cout << "Inserire il giorno in cui e' stata effettuata la transazione:" << endl;
                            cin >> g;
                            cout << "Inserire il mese in cui e' stata effettuata la transazione: " << endl;
                            cin >> m;
                            cout << "Inserire l'anno in cui e' stata effettuata la transazione: " << endl;
                            cin >> a;
                            d->setGiorno(g);
                            d->setMese(m);
                            d->setAnno(a);
                            if (d->isValid())
                                f2 = true;
                            else cout << "La data inserita non e' valida, si prega di inserirne un altra!" << endl;
                        }
                        t->setTipo(type);
                        t->setImporto(v);
                        t->setDescrizione(descrizione);
                        t->setData(*d);
                        c.aggiungiTransazione(*t);
                        cout << "La transazione e' stata eseguita con successo" << endl;
                        addt << type << " " << v << " "<< descrizione << " " << g << " " << m << " " << a << "\n";
                        break;
                    case 2:
                        type=false;
                        f2=false;
                        cout << "Inserire l'ammontare che si desidera prelevare:"<< endl;
                        cin >> v;
                        cout << "Inserire una descrizione per la nuova transazione:" << endl;
                        cin >> descrizione;
                        while(!f2) {
                            cout << "Inserire il giorno in cui e' stata effettuata la transazione:" << endl;
                            cin >> g;
                            cout << "Inserire il mese in cui e' stata effettuata la transazione:" << endl;
                            cin >> m;
                            cout << "Inserire l'anno in cui e' stata effettuata la transazione:" << endl;
                            cin >> a;
                            d->setGiorno(g);
                            d->setMese(m);
                            d->setAnno(a);
                            if (d->isValid())
                                f2 = true;
                            else cout << "La data inserita non e' valida, si prega di inserirne un altra!" << endl;
                        }
                        t->setTipo(type);
                        t->setImporto(v);
                        t->setDescrizione(descrizione);
                        t->setData(*d);
                        c.aggiungiTransazione(*t);
                        cout << "La transazione e' stata eseguita con successo" << endl;
                        addt << type << " " << v << " "<< descrizione << " " << g << " " << m << " " << a << "\n";
                        break;
                    case 0:
                        cout << "Procedo a visualizzare nuovamente il menu' iniziale" << endl;
                        break;
                    default:
                        cout << "Il numero inserito non corrisponde a nessuna operazione" << endl;
                        break;
                }
                addt.close();
                break;
            case 3:
                c.stampaTransazioni();
                break;
            case 0:
                cout << "Grazie per aver usufruito del nostro servizio" << endl;
                f1 = true;
                break;
            default:
                cout << "Il numero inserito non corrisponde a nessuna operazione" << endl;
                break;
        }
    }
    file.close();
    return 0;
}