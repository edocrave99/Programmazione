#include "gtest/gtest.h"

#include "../Conto.h"
#include <fstream>

using namespace std;

class ContoSuite : public ::testing::Test {

protected:

    virtual void SetUp(){
        c.setSaldo(1000);
    }

    Conto c;
    Transazione t;
    Data d;
    ifstream file;
};

TEST_F(ContoSuite, TestTransazioneIngresso){
    d=Data();
    t.setImporto(1500);
    t.setTipo(true);
    t.setDescrizione("stipendio");
    t.setData(d);
    c.aggiungiTransazione(t, "ContoProva.txt");

    ASSERT_EQ(2500, c.getSaldo());
}

TEST_F(ContoSuite, TestTransazioneUscita){
    t.setImporto(250);
    t.setTipo(false);
    c.aggiungiTransazione(t, "ContoProva.txt");

    ASSERT_EQ(750, c.getSaldo());
}

TEST_F(ContoSuite, TestTransazioneUscitaNegata){
    t.setImporto(2500);
    t.setTipo(false);
    d=Data();
    t.setData(d);
    c.aggiungiTransazione(t, "ContoProva.txt");

    ASSERT_EQ(1000, c.getSaldo());
}

TEST_F(ContoSuite, TestControlloFile){
    file.open("Conto.txt");
    float s, i;
    bool type;
    string desc;
    int g, m, a;

    s=c.getSaldo();

    while(file >> type >> i >> desc >> g >> m >> a ) {
        d=Data(g,m,a);
        t.setTipo(type);
        t.setImporto(i);
        t.setDescrizione(desc);
        t.setData(d);
        c.leggiTransazione(t);

        if (type == 1)
            s += i;
        else s -= i;
    }
    ASSERT_EQ(s, c.getSaldo());
}

TEST_F(ContoSuite, TestCancellazioneFallita){
    c.cancellaTransazione("ContoProva.txt");
    ASSERT_EQ(1000, c.getSaldo());
}

TEST_F(ContoSuite, TestCancellazioneRiuscita){
    d=Data();
    t.setImporto(1500);
    t.setTipo(true);
    t.setDescrizione("stipendio");
    t.setData(d);
    c.cancellaTransazione("ContoProva.txt");
    ASSERT_EQ(1000, c.getSaldo());
}

TEST_F(ContoSuite, TestModificaFallita){
    t.setImporto(1500);
    t.setTipo(true);
    d=Data();
    t.setData(d);
    c.modificaTransazione("ContoProva.txt");

    ASSERT_EQ(1000, c.getSaldo());
}