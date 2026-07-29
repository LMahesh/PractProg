#include "pch.h"
#include "sample.h"
//#include "../"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
  EXPECT_EQ(decodeRLE("2a3b"),"aabbb");
  EXPECT_TRUE(decodeRLE("2a3b")== "aabbb");
}