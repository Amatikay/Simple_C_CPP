#pragma once
#include <map>
#include <ostream>

class Date {
 public:
  static constexpr int daysCountInYear = 365;
  Date(int day, int month, int year);
  int GetDay() const { return day; };
  int GetMonth() const { return month; };
  int GetYear() const { return year; };
  Date operator+(const int& n) const;
  Date operator-(const int& n) const;

 private:
  int day, month, year;
  void setDefault();
  const std::map<int, int> daysNumberInMonth{
      {1, 31},   // January
      {2, 28},   // February
      {3, 31},   // March
      {4, 30},   // April
      {5, 31},   // May
      {6, 30},   // June
      {7, 31},   // July
      {8, 31},   // August
      {9, 30},   // September
      {10, 31},  // October
      {11, 30},  // November
      {12, 31}   // December
  };
  static bool isLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
  };
};

std::ostream& operator<<(std::ostream& out, const Date& d);