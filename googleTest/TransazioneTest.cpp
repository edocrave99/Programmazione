#include "gtest/gtest.h"

#include "../Transazione.h"
#include "../Data.h"

TEST(Transazione, DefaultConstructor) {
    Transazione t;
    ASSERT_EQ(0, t.getImporto());
}

TEST(Transazione, Constructor) {
    Data d= Data();
    ASSERT_THROW(Transazione t(1, "spesa", -200, d) , std::invalid_argument);
}