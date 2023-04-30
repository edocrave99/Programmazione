#include "gtest/gtest.h"

#include "../Transazione.h"

TEST(Transazione, DefaultConstructor) {
    Transazione t;
    ASSERT_EQ(0, t.getImporto());
}