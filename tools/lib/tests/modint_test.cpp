#include "gtest/gtest.h"
#include "modint.hh"

TEST(ModIntTest, Calculation) {
    using mint = mint<7>;
    EXPECT_EQ(mint(3), mint(1)+mint(2));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}