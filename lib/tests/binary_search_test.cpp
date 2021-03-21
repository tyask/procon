#include "gtest/gtest.h"
#include "binary_search.hh"

using namespace std;

TEST(BinarySearchTest, TestForContainer) {
    vector<int> v{1, 3, 5, 7, 9};
    int idx = fumin::binary_search<int>(-1, v.size(), [&](int idx) { return v[idx] >= 4; });
    ASSERT_EQ(idx, 2);
}

TEST(BinarySearchTest, TestForSequence) {
    int idx = fumin::binary_search<int>(10-1, 100+1, [](int val) { return val >= 25; });
    ASSERT_EQ(idx, 25);

    idx = fumin::binary_search<int>(10-1, 100+1, [](int val) { return val >= 110; });
    ASSERT_EQ(idx, 101);

    idx = fumin::binary_search<int>(10-1, 100+1, [](int val) { return val >= 5; });
    ASSERT_EQ(idx, 10);
}


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}