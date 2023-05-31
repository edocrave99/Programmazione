#include "gtest/gtest.h"

#include "../Data.h"

TEST(Data, DefaultConstructor) {
    Data d;
    ASSERT_EQ(1, d.getGiorno());
    ASSERT_EQ(1, d.getMese());
    ASSERT_EQ(2000, d.getAnno());
}