#include <pthread.h>

#include <fstream>
#include <iostream>
#include <map>

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

Date::Date(int day, int month, int year) : day(day), month(month), year(year) {
  if ((day > 31 || day < 1) || (month > 12 || month < 1) ||
      (year > 2099 || year < 1970)) {
    setDefault();
  }
};

void Date::setDefault() {
  day   = 1;
  month = 1;
  year  = 1970;
}

Date Date::operator+(const int& n) const {
  int resultYear  = this->year;
  int resultMonth = this->month;
  int resultDay   = this->day;
  int daysAccum   = 0;
  while (n / (daysAccum +
              (daysCountInYear + static_cast<int>(isLeap(resultYear))))) {
    daysAccum += daysCountInYear + static_cast<int>(isLeap(resultYear++));
  }
  while (n / (daysAccum + (daysNumberInMonth.at(resultMonth)))) {
    daysAccum += daysNumberInMonth.at(resultMonth++);
    if (resultMonth > 12) {
      resultYear++;
      resultMonth = 1;
    }
  }
  resultDay += n - daysAccum;
  if (resultDay > daysNumberInMonth.at(resultMonth)) {
    resultDay -= daysNumberInMonth.at(resultMonth++);
  }
  if (resultMonth > 12) {
    resultYear++;
    resultMonth = 1;
  }
  return Date(resultDay, resultMonth, resultYear);
}

std::ostream& operator<<(std::ostream& out, const Date& d) {
  out << d.GetDay() << "." << d.GetMonth() << "." << d.GetYear();
  return out;
}

int main() {
  std::ifstream file(
      "/home/engelke-sergey/Projects/Simple_C_CPP/Test/input_data");
  int a, b, c;
  file >> a >> b >> c;
  auto dayFromFile = Date(a, b, c);

  std::cout << dayFromFile << std::endl;
  std::cout << dayFromFile + 245 << std::endl;   // 15.02.2024
  std::cout << dayFromFile + 1019 << std::endl;  // 30.03.2026
}