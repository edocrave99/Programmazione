#include <iostream>
#include <fstream>
#include "Conto.h"
#include "Transazione.h"
#include <string>

using namespace std;

/* Classi che rappresentano transazioni finanziarie su un conto corrente (ingresso e uscita).
    Le classi devono essere in gradi leggere e salvare i dati su file. */

int main() {
    string descrizione;
    //variabile per inserire la descrizione di una nuova transazione, inizialmente viene usata anche per attribuire il nome al conto

    cout << "Inserire un nome per il proprio conto: " << endl;
    cin >> descrizione;
    Conto c(descrizione, 0);
    auto t = Transazione();

    int sel1, sel2, g, m, a;
    //le variabili sel1 e sel2 servono per gestire gli switch case, mentre g,m,a servonjo invece per la data delle eventuali nuove transazioni
    float s;
    //variabili usata per visualizzare il saldo del conto e per settare l'importo delle transazioni
    bool f1 = false,type, f2;
    //f1 serve per gestire il ciclo all'interno del quale è inserito lo switch, f2  gestisce il ciclo per l'inserimento della data di una transazione, mentre type serve per stabilire il tipo delle transazioni (ingresso o uscita), type servira' invece per impostare il tipo delle transazioni

    c.aggiornamentoIniziale("Conto.txt");
    //le transazioni presenti sul file vengono inserite nella lista

    cout << "Benvenuto sul gestore di transazione finanziarie di Cravegni Edoardo" << endl;
    while (!f1) {

        cout << "Ecco le operazioni che posso effettuare:" << endl;
        cout << "1) Visualizza il tuo saldo" << endl;
        cout << "2) Effettua una transazione" << endl;
        cout << "3) Visualizza il tuo storico delle transazioni" << endl;
        cout << "4) Modifica una transazione" << endl;
        cout << "5) Cancella una transazione" << endl;
        cout << "0) Uscire" << endl;

        cout << "Inserire il numero corrispondente all'operazione che si desidera effettuare:" << endl;
        cin >> sel1;

        switch (sel1) {
            //nello switch esterno si andra' a gestire il menu' con tutte le operazioni
            case 1:
                s = c.getSaldo();
                cout << "Il saldo attuale e': " << s << endl;

                break;

            case 2:

                cout << "Che tipo di transazione desidera effettuare:" << endl;
                cout << "1) In ingresso" << endl;
                cout << "2) In uscita" << endl;
                cout << "0) Torna indietro" << endl;

                cout << "Inserire il numero corrispondente:" << endl;
                cin >> sel2;

                switch (sel2) {
                    //nello switch interno si gestira' invece l'aggiunta di una transazione, distinguendole in transazioni in ingresso e uscita
                    case 1:
                        type=true;
                        f2=false;
                        cout << "Inserire il valore da aggiungere al saldo:" << endl;
                        while(!f2) {
                            cin >> s;
                            f2=t.setImporto(s);
                            if(!f2)
                                cout << "L'importo inserito non e' valido, si prega di inserirne un altro: " << endl;
                        }
                        cout << "Inserire una descrizione per la nuova transazione:" << endl;
                        cin >> descrizione;
                        f2=false;
                        do{
                            cout << "Inserire il giorno in cui e' stata effettuata la transazione:" << endl;
                            cin >> g;
                            cout << "Inserire il mese in cui e' stata effettuata la transazione:" << endl;
                            cin >> m;
                            cout << "Inserire l'anno in cui e' stata effettuata la transazione:" << endl;
                            cin >> a;
                            try{
                                Data d = Data(g,m,a);
                                f2 = d.isValid(g,m,a);
                                t.setTipo(type);
                                t.setDescrizione(descrizione);
                                t.setData(d);
                            }
                            catch (const invalid_argument& e) {
                                cout << e.what() << endl;
                            }
                        } while(!f2);
                        f2=c.aggiungiTransazione(t, "Conto.txt");

                        if(f2)
                            cout << "La transazione e' stata eseguita con successo" << endl;
                        else cout << "Si e' verificato un errore nella transazione" << endl;

                        break;

                    case 2:
                        type=false;
                        f2=false;
                        cout << "Inserire l'ammontare che si desidera prelevare:"<< endl;
                        while(!f2) {
                            cin >> s;
                            f2=t.setImporto(s);
                            if(!f2)
                                cout << "L'importo inserito non e' valido, si prega di inserirne un altro: " << endl;
                        }
                        cout << "Inserire una descrizione per la nuova transazione:" << endl;
                        cin >> descrizione;
                        f2=false;
                        do{
                            cout << "Inserire il giorno in cui e' stata effettuata la transazione:" << endl;
                            cin >> g;
                            cout << "Inserire il mese in cui e' stata effettuata la transazione:" << endl;
                            cin >> m;
                            cout << "Inserire l'anno in cui e' stata effettuata la transazione:" << endl;
                            cin >> a;
                            try{
                                Data d = Data(g,m,a);
                                f2 = d.isValid(g,m,a);
                                t.setTipo(type);
                                t.setDescrizione(descrizione);
                                t.setData(d);
                            }
                            catch (const invalid_argument& e) {
                                cout << e.what() << endl;
                            }
                        } while(!f2);
                        f2=c.aggiungiTransazione(t, "Conto.txt");

                        if(f2)
                            cout << "La transazione e' stata eseguita con successo" << endl;
                        else cout << "La transazione non e' stata eseguita, in quanto il credito per completarla non era sufficiente" << endl;

                        break;

                    case 0:
                        cout << "Procedo a visualizzare nuovamente il menu' iniziale" << endl;

                        break;

                    default:
                        cout << "Il numero inserito non corrisponde a nessuna operazione" << endl;

                        break;
                }

                break;

            case 3:
                c.stampaTransazioni();

                break;

            case 4:
                c.modificaTransazione("Conto.txt");

                break;

            case 5:
                c.cancellaTransazione("Conto.txt");

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
    return 0;
}