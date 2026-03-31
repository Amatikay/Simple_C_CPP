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
  int operator-(const Date& date) const;

 private:
  int day, month, year;
  void setDefault();
  static const std::map<int, int> daysNumberInMonth;
  static bool isLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
  };
};

std::ostream& operator<<(std::ostream& out, const Date& d);