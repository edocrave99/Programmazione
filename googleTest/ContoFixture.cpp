#include "gtest/gtest.h"

#include "../Conto.h"

class ContoSuite : public ::testing::Test {

protected:

    virtual void SetUp(){
        c.setSaldo(1000);
    }

    Conto c;
    Transazione t;
};

TEST_F(ContoSuite, TestTransazioneIngresso){
    t.setImporto(1500);
    t.setTipo(true);
    c.aggiungiTransazione(t);

    ASSERT_EQ(2500, c.getSaldo());
}

TEST_F(ContoSuite, TestTransazioneUscita){
    t.setImporto(250);
    t.setTipo(false);
    c.aggiungiTransazione(t);

    ASSERT_EQ(750, c.getSaldo());
}

TEST_F(ContoSuite, TestTransazioneUscitaNegata){
    t.setImporto(2500);
    t.setTipo(false);
    c.aggiungiTransazione(t);

    ASSERT_EQ(1000, c.getSaldo());
}