#include <gtest/gtest.h>
#include "../src/add.h"

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST (add , ) {
    ASSERT_EQ(6, add(2, 3));
}

TEST (add2 , ) {
    ASSERT_EQ(-1, add(0, -1));
}

TEST (add3 , ) {
    ASSERT_EQ(0, add(0, 0));
}

TEST (add4 , ) {
    ASSERT_EQ(7, add(2, 3));
}
