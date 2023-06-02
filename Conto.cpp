#include "Conto.h"
#include "Transazione.h"
#include "Data.h"
#include <iostream>
#include <fstream>

using namespace std;

Conto::Conto() {
    setSaldo(0);
}

Conto::Conto(string nome, float saldo) : nome(nome), saldo(saldo) {}

float Conto::getSaldo() const {
    return saldo;
}

bool Conto::setSaldo(float saldo) {
    if(saldo >=0) {
        Conto::saldo = saldo;           //non è previsto il saldo negativo
        return true;
    }
    else return false;
}

bool Conto::aggiungiTransazione(const Transazione &t, string path) {
    ofstream addt;
    //dichairo un oggetto di tipo ofstream(solo scrittura) che servira' nel caso in cui si aggiungano delle transazioni

    addt.open(path, std::ios::app);
    //apre il indicando di posizionarsi in scrittura sempre alla fine del file, in modo tale da non sovrascrivere le altre transazioni

    bool r = true;
    Data d;

    if(t.getTipo()==0)
        if(t.getImporto()>saldo)
            r=false;
        else {
            listaTransazioni.push_back(t);
            saldo-=t.getImporto();
            d = t.getData();
            addt << t.getTipo() << " " << t.getImporto() << " "<< t.getDescrizione() << " " << d.getGiorno() << " " << d.getMese()<< " " << d.getAnno() << "\n";
        }
    else {
        listaTransazioni.push_back(t);
        saldo+=t.getImporto();
        d = t.getData();
        addt << t.getTipo() << " " << t.getImporto() << " "<< t.getDescrizione() << " " << d.getGiorno() << " " << d.getMese()<< " " << d.getAnno() << "\n";
    }
    addt.close();
    //funzione utilizzata per poter chiudere il file associato all'oggetto

    return r;
}

void Conto::stampaTransazioni() const {
    if (listaTransazioni.empty()) {
        cout << "La lista delle transazioni al momento e' vuota!" << endl;
    }
    else{
        cout << "TRANSAZIONI:" << endl;
        cout << endl;
        int i = 0;
        for (const auto &t: listaTransazioni) {
            string s;
            cout << i << ")" << endl;
            cout << "Tipo: ";
            auto tipo = t.getTipo();
            if (tipo)
                cout << "In ingresso" << endl;
            else cout << "In uscita" << endl;
            cout << "Importo: ";
            cout << t.getImporto() << endl;
            cout << "Data: ";
            auto d = t.getData();
            s = d.toString();
            cout << s;
            cout << endl;
            cout << "Descrizione: ";
            cout << t.getDescrizione() << endl;
            cout << endl;
            i++;
        }
    }
}

void Conto::aggiornamentoIniziale(string path){
    ifstream file;
    file.open(path);
    //apre il file di testo contenente le transazioni usando un oggetto della classe ifstream(solo lettura)

    bool type;
    float s;
    string descrizione;          //variabili per la lettura dei dati delle transazioni sul file
    int g, m, a;
    auto t = Transazione();
    Data d;

    while(file >> type >> s >> descrizione >> g >> m >> a) {
        d=Data(g,m,a);
        t.setTipo(type);                                   //ciclo per prelevare le transazioni dal file ed inserirle nella listaTransazioni
        t.setImporto(s);
        t.setDescrizione(descrizione);
        t.setData(d);
        leggiTransazione(t);
    }

    file.close();
}

void Conto::leggiTransazione(const Transazione &t){
    //si differenzia da aggiungiTransazione() in quanto questo metodo non scrive sul file, ed infatti viene utilizzato solamente nel metodo
    // aggiornamentoIniziale() all'avvio del programma

    if(t.getTipo()==0){
            listaTransazioni.push_back(t);
            Conto::saldo-=t.getImporto();
    }
    else {
        listaTransazioni.push_back(t);
        Conto::saldo+=t.getImporto();
    }
}

void Conto::modificaTransazione(string path) {
    if (listaTransazioni.empty()) {
        cout << "Non e' stato possibile modificare una transazione, perche' la lista al momento e' vuota!" << endl;
    }
    else {
        int pos, i, sel, a;     //i e sel vengono usati anche per la nuova data
        string desc;
        bool f = false;
        Data d;

        stampaTransazioni();
        while (!f) {
            cout << "Inserire la posizione della transazione che si desidera modificare: " << endl;
            cin >> pos;
            if (pos < 0 || pos >= listaTransazioni.size())
                cout << "Il numero inserito non e' valido, si prega di inserirne un altro!" << endl;
            else f = true;
        }
        auto it = listaTransazioni.begin();
        advance(it, pos);
        if ((*it).getTipo())
            Conto::saldo -= (*it).getImporto();
        else Conto::saldo += (*it).getImporto();

        while (f) {
            cout << "Inserire il tipo della transazione:" << endl;
            cout << "0) In uscita" << endl;
            cout << "1) In ingresso" << endl;
            cin >> sel;
            if (sel == 0 || sel == 1)
                f = false;
            else cout << "Il numero inserito non e' valido!" << endl;
        }
        if (sel == 0)
            (*it).setTipo(false);
        else (*it).setTipo(true);

        while (!f) {
            cout << "Inserire l'importo della transazione:" << endl;
            cin >> i;
            if ((*it).getTipo() && Conto::saldo < i) {
                cout << "Non e' possibile effettuare una transazione in uscita con il seguente importo, alrimenti "
                        "il saldo andrabbe in negativo, si prega di inserirne un altra!" << endl;
                f = false;
            }
            else f = (*it).setImporto(i);
        }

        cout << "Inserire una descrizione per la transazione:" << endl;
        cin >> desc;
        (*it).setDescrizione(desc);

        while (f) {
            cout << "Inserire il giorno in cui e' stata effettuata la transazione:" << endl;
            cin >> i;
            cout << "Inserire il mese in cui e' stata effettuata la transazione: " << endl;
            cin >> sel;
            cout << "Inserire l'anno in cui e' stata effettuata la transazione: " << endl;
            cin >> a;

            d = Data(i, sel, a);
            if (d.isValid(i, sel, a))
                f = false;
            else cout << ", si prega di inserirne un altra!" << endl;
        }
        (*it).setData(d);

        if ((*it).getTipo()) {
            Conto::saldo += (*it).getImporto();
            riscriviFile(path);
            cout << "La modifica e' stata effettuata con successo!" << endl;
        }
        else {
            Conto::saldo -= (*it).getImporto();
            riscriviFile(path);
            cout << "La modifica e' stata effettuata con successo!" << endl;
        }
    }
}

void Conto::cancellaTransazione(string path) {
    if (listaTransazioni.empty()) {
        cout << "Non e' stato possibile modificare una transazione, perche' la lista al momento e' vuota!" << endl;
    } else {
        int pos;
        bool f = false;
        stampaTransazioni();
        while (!f) {
            cout << "Inserire la posizione della transazione che si desidera rimuovere: " << endl;
            cin >> pos;
            if (pos < 0 || pos >= listaTransazioni.size())
                cout << "Il numero inserito non e' valido, si prega di inserirne un altro!" << endl;
            else f = true;
        }
        auto it = listaTransazioni.begin();
        advance(it, pos);
        if ((*it).getTipo())
            Conto::saldo -= (*it).getImporto();
        else Conto::saldo += (*it).getImporto();
        listaTransazioni.erase(it);
        cout << "La cancellazione e' stata effettuata con successo!" << endl;
        riscriviFile(path);
    }
}

void Conto::riscriviFile(string path){
    const char* cpath = path.c_str();
    remove(cpath);
    ofstream file;
    file.open(path);
    for(auto & it : listaTransazioni)
        file << it.getTipo() << " " << it.getImporto() << " " << it.getDescrizione() << " " << it.getData().getGiorno() << " " << it.getData().getMese() << " " << it.getData().getAnno() << "\n";
    file.close();
}
