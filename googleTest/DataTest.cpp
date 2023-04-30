#include "gtest/gtest.h"

#include "../Data.h"

TEST(Data, DefaultConstructor) {
    Data d;
    ASSERT_EQ(0, d.getGiorno());
    ASSERT_EQ(0, d.getMese());
    ASSERT_EQ(0, d.getAnno());
    ASSERT_FALSE(d.isValid());
}