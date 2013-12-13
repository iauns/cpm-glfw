#include <iostream>
#include <gtest/gtest.h>

TEST(BasicTests, TestTrue)
{
  ASSERT_EQ(1, 1);
  EXPECT_THROW(throw std::exception(), std::exception);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
