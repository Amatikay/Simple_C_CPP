
#include <fstream>
#include <iostream>

#include "date.hpp"

int main() {
  std::ifstream file("../../../Test/input_data");
  int a, b, c;
  file >> a >> b >> c;
  auto dayFromFile = Date(a, b, c);

  std::cout << dayFromFile << std::endl;
  std::cout << dayFromFile + 245 << std::endl;   // 15.02.2024
  std::cout << dayFromFile + 1019 << std::endl;  // 30.03.2026
}