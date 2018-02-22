#include <gtest/gtest.h>
#include "../src/add.h"

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST ( , normal) {
    ASSERT_EQ(5, add(2, 6));
}

TEST ( , hihih) {
    ASSERT_EQ(-1, add(0, -1));
}

TEST ( , test1) {
    ASSERT_EQ(0, add(0, 0));
}

TEST ( , test2) {
    ASSERT_EQ(6, add(2, 3));
}
