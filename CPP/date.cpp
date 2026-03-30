#include "date.hpp"

#include <ostream>

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