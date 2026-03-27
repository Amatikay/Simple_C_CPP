#include <gtest/gtest.h>

#include <algorithm>
#include <deque>
#include <list>
#include <vector>

#include "foo.hpp"

TEST(YandexHandbook, Uniue) {
  std::vector<int> vectorStd = {5, 5, 3, 2, 2, 5, 9, 1};
  std::vector<int> vectorCustom = {5, 5, 3, 2, 2, 5, 9, 1};
  auto iterS = std::unique(vectorStd.begin(), vectorStd.end());
  auto iterC = cpp::Unique(vectorCustom.begin(), vectorCustom.end());

  EXPECT_EQ(std::distance(vectorStd.begin(), iterS),
            std::distance(vectorCustom.begin(), iterC));

  EXPECT_TRUE(
      std::equal(vectorStd.begin(), iterS, vectorCustom.begin(), iterC));

  EXPECT_TRUE(
      std::is_permutation(iterS, vectorStd.end(), iterC, vectorCustom.end()));
}

TEST(YandexHandbook, SetDifference) {
  std::vector<int> a = {1, 3, 5, 5, 7};
  std::list<int> b = {1, 1, 2, 3, 5};

  std::deque<int> resultStd;
  std::deque<int> resultCustom;

  std::set_difference(a.begin(), a.end(), b.begin(), b.end(),
                      std::back_inserter(resultStd));

  cpp::SetDifference(a.begin(), a.end(), b.begin(), b.end(),
                     std::back_inserter(resultCustom));

  EXPECT_EQ(resultStd.size(), resultCustom.size());

  EXPECT_TRUE(std::equal(resultStd.begin(), resultStd.end(),
                         resultCustom.begin(), resultCustom.end()));
}
