#include <gtest/gtest.h>
#include <gmock/gmock.h> 

#include <stdarg.h>

#include "../include/MyBinarySearch.hpp"

namespace MyBinarySearch
{

vector<int> makeVector(int size, ...){
  va_list argptr;
  va_start(argptr, size);

  vector<int> v;
  for (int i = 0; i < size; i++)
  {
    v.push_back(va_arg(argptr, int));
  }

  va_end(argptr);

  // std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
  // std::cout << std::endl;

  return v;
}

TEST(binarySearch, simpleTest){
  vector<int> v{-1, 0, 3, 5, 9, 12};
  EXPECT_EQ(binarySearch(v, 3), 2);

  v = makeVector(5, 1, 2, 3, 4, 5);
  EXPECT_EQ(binarySearch(v, 3), 2);

  v = makeVector(3, -1, 2, 3);
  EXPECT_EQ(binarySearch(v, 3), 2);

  v = makeVector(13, -10, -9, -6, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
  EXPECT_EQ(binarySearch(v, -10), 0);

  EXPECT_EQ(binarySearch(v, 10), 12);

  EXPECT_EQ(binarySearch(v, -12), -1);

  v = makeVector(1, -10);
  EXPECT_EQ(binarySearch(v, -10), 0);

  EXPECT_EQ(binarySearch(v, -11), -1);

  v = makeVector(0);
  EXPECT_EQ(binarySearch(v, -10), -1);
}

}