#include <gtest/gtest.h>
#include "../src/add.h"

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST (add, normal) {
    ASSERT_EQ(5, add(2, 3));
}

TEST (add, hihih) {
    ASSERT_EQ(-1, add(0, -1));
}

TEST (add, test1) {
    ASSERT_EQ(0, add(0, 0));
}
