#include "Conto.h"
#include "Transazione.h"
#include <iostream>
#include <fstream>

using namespace std;

Conto::Conto() {
    setSaldo(0);
}

Conto::Conto(float saldo) : saldo(saldo) {}

float Conto::getSaldo() const {
    return saldo;
}

void Conto::setSaldo(float saldo) {
    Conto::saldo=saldo;
}

bool Conto::aggiungiTransazione(const Transazione &t) {
    ofstream addt;
    //dichairo un oggetto di tipo ofstream(solo scrittura) che servira' nel caso in cui si aggiungano delle transazioni

    addt.open(R"(C:\Elaborato\cmake-build-debug\Conto.txt)", std::ios::app);
    //apre il indicando di posizionarsi in scrittura sempre alla fine del file, in modo tale da non sovrascrivere le altre transazioni

    bool r = true;
    auto *d = new Data();

    if(t.getTipo()==0)
        if(t.getImporto()>saldo)
            r=false;
        else {
            listaTransazioni.push_back(t);
            saldo-=t.getImporto();
            *d = t.getData();
            addt << t.getTipo() << " " << t.getImporto() << " "<< t.getDescrizione() << " " << d->getGiorno() << " " << d->getMese()<< " " << d->getAnno() << "\n";
        }
    else {
        listaTransazioni.push_back(t);
        saldo+=t.getImporto();
        *d = t.getData();
        addt << t.getTipo() << " " << t.getImporto() << " "<< t.getDescrizione() << " " << d->getGiorno() << " " << d->getMese()<< " " << d->getAnno() << "\n";
    }
    addt.close();
    //funzione utilizzata per poter chiudere il file associato all'oggetto

    return r;
}

void Conto::aggiungiTransazioneTest(const Transazione &t) {
    //Metodo usato nella unit testing in modo da non alterare listaTransazioni ed il file contenente le transazioni

    if(t.getTipo()==1)
        saldo+=t.getImporto();
    else if(t.getImporto() <= saldo)
            saldo-=t.getImporto();
         else
            cout << "Non e' stato possibile effettuare la transazione in quanto il saldo attuale non era sufficiente" ;
}

void Conto::stampaTransazioni() const {
    cout << "TRANSAZIONI:" << endl;
    cout << endl;

    for (const auto &t: listaTransazioni) {
        cout << "Tipo: ";
        auto tipo = t.getTipo();
        if (tipo == true)
            cout << "In ingresso" << endl;
        else cout << "In uscita" << endl;
        cout << "Importo: ";
        cout << t.getImporto() << endl;
        cout << "Data: ";
        auto d = t.getData();
        d.stampaData();
        cout << endl;
        cout << "Descrizione: ";
        cout << t.getDescrizione() << endl;
        cout << endl;
    }
}

void Conto::aggiornamentoIniziale(){
    ifstream file(R"(C:\Elaborato\cmake-build-debug\Conto.txt)");
    //apre il file di testo contenente le transazioni usando un oggetto della classe ifstream(solo lettura)

    bool type;
    float s;
    string descrizione;          //variabili per la lettura dei dati delle transazioni sul file
    int g, m, a;
    auto *t = new Transazione();
    auto *d = new Data();

    while(file >> type >> s >> descrizione >> g >> m >> a) {
        d->setGiorno(g);
        d->setMese(m);
        d->setAnno(a);
        t->setTipo(type);                                   //ciclo per prelevare le transazioni dal file ed inserirle nella listaTransazioni
        t->setImporto(s);
        t->setDescrizione(descrizione);
        t->setData(*d);
        scaricaTransazione(*t);
    }

    file.close();
}

void Conto::scaricaTransazione(const Transazione &t){
    //si differenzia da aggiungiTransazione() in quanto questo metodo non scrive sul file, ed infatti viene utilizzato solamente nel metodo
    // aggiornamentoIniziale() all'avvio del programma

    if(t.getTipo()==0){
            listaTransazioni.push_back(t);
            saldo-=t.getImporto();
    }
    else {
        listaTransazioni.push_back(t);
        saldo+=t.getImporto();
    }
}

void Conto::scaricaTransazioneTest(const Transazione &t){
    //si differenzia da scaricaTransazione() in quanto questo metodo non inserisce la transazione in listaTransazioni, infatti viene usato
    //solamente all'interno della unit testing

    if(t.getTipo()==0)
        saldo-=t.getImporto();
    else
        saldo+=t.getImporto();
}