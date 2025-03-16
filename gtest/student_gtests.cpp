#include <gtest/gtest.h>

#include "dijkstras.h"
#include "ladder.h"

TEST(Ladder, is_adjancent) {
    EXPECT_TRUE(is_adjacent("abc","abd"));
    EXPECT_FALSE(is_adjacent("Abc","abd"));
    EXPECT_TRUE(is_adjacent("bc","abc"));
    EXPECT_TRUE(is_adjacent("abc","ab"));
    EXPECT_FALSE(is_adjacent("cbc","abd"));
}
