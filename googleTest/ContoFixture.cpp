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
    t.setImporto(1500);
    t.setTipo(true);
    c.aggiungiTransazioneTest(t);

    ASSERT_EQ(2500, c.getSaldo());
}

TEST_F(ContoSuite, TestTransazioneUscita){
    t.setImporto(250);
    t.setTipo(false);
    c.aggiungiTransazioneTest(t);

    ASSERT_EQ(750, c.getSaldo());
}

TEST_F(ContoSuite, TestTransazioneUscitaNegata){
    t.setImporto(2500);
    t.setTipo(false);
    c.aggiungiTransazioneTest(t);

    ASSERT_EQ(1000, c.getSaldo());
}

TEST_F(ContoSuite, TestControlloFile){
    file.open((R"(C:\Elaborato\cmake-build-debug\Conto.txt)"));
    float s, i;
    bool type;
    string desc;
    int g, m, a;

    s=c.getSaldo();

    while(file >> type >> i >> desc >> g >> m >> a ) {
        d.setGiorno(g);
        d.setMese(m);
        d.setAnno(a);
        t.setTipo(type);
        t.setImporto(i);
        t.setDescrizione(desc);
        t.setData(d);

        c.scaricaTransazioneTest(t);

        if (type == 1)
            s += i;
        else s -= i;
    }
    ASSERT_EQ(s, c.getSaldo());
}