#include <iostream>
#include <stack>

// () - Parentheses
// [] - Brackets
// {} - Braces

// [(]{})     - Неверно
// {(())()}[] - Верно

enum class Brasket { PARENTHES, BRASKET, BRACE };

int main() {
  std::stack<Brasket> braskets;
  std::string bracketStr{};
  std::cin >> bracketStr;
  if (bracketStr.empty()) {
    std::cout << "YES" << std::endl;
    return 0;
  }
  for (auto const &bracket : bracketStr) {
    switch (bracket) {
      case ')':
        if (!braskets.empty() && braskets.top() == Brasket::PARENTHES) {
          braskets.pop();
          continue;
        } else {
          std::cout << "NO" << std::endl;
          return 0;
        }
      case ']':
        if (!braskets.empty() && braskets.top() == Brasket::BRASKET) {
          braskets.pop();
          continue;
        } else {
          std::cout << "NO" << std::endl;
          return 0;
        }
      case '}':
        if (!braskets.empty() && braskets.top() == Brasket::BRACE) {
          braskets.pop();
          continue;
        } else {
          std::cout << "NO" << std::endl;
          return 0;
        }
    }
    switch (bracket) {
      case '(':
        braskets.push(Brasket::PARENTHES);
        continue;
      case '[':
        braskets.push(Brasket::BRASKET);
        continue;
      case '{':
        braskets.push(Brasket::BRACE);
        continue;
    }
  }
  if (braskets.empty()) {
    std::cout << "YES" << std::endl;
    return 0;
  } else {
    std::cout << "NO" << std::endl;
    return 0;
  }
}
