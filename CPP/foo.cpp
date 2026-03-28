#include "foo.hpp"

namespace cpp {

bool NextToken(std::string_view &sv, const char delimiter,
               std::string_view &token) {
  if (sv.empty()) return false;
  auto pos = sv.find(delimiter);
  if (std::string::npos == pos) {
    token = sv.substr(0, sv.size());
    sv.remove_prefix(sv.size());
  } else {
    token = sv.substr(0, pos);
    sv.remove_prefix(pos + 1);
  }
  return true;
}

}  // namespace cpp