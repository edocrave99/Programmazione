#include "gtest/gtest.h"

#include "../Conto.h"

TEST(Conto, DefaultConstructor) {
    Conto c;
    ASSERT_EQ(0, c.getSaldo());
}