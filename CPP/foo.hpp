#pragma once
#include <iostream>
namespace cpp {

template <typename Iter>
Iter Unique(Iter first, Iter last) {
  if (first == last) {
    return last;
  }
  Iter result = first;
  for (Iter it = std::next(first); it != last; ++it) {
    if (*result != *it) {
      ++result;
      *result = *it;
    }
  }
  return ++result;
}

template <typename InIter1, typename InIter2, typename OutIter>
OutIter SetDifference(InIter1 first1, InIter1 last1, InIter2 first2,
                      InIter2 last2, OutIter out) {
  while (first1 != last1) {
    if (first2 == last2) {
      *out++ = *first1++;
      continue;
    }

    if (*first1 < *first2) {
      *out++ = *first1++;
    } else if (*first2 < *first1) {
      ++first2;
    } else {
      ++first1;
      ++first2;
    }
  }
  return out;
}

template <typename Container>
void printContainer(const Container& container) {
  for (const auto& i : container) {
    std::cout << i << " ";
  }
  std::cout << '\n';
}

}  // namespace cpp