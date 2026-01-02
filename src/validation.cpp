#include "validation.hpp"
#include <regex>

bool is_positive_id(int id) {
  return id > 0;
}

bool is_valid_email(const std::string& email) {
  // simple practical regex (enough for course project)
  static const std::regex re(R"(^[A-Za-z0-9._%+\-]+@[A-Za-z0-9.\-]+\.[A-Za-z]{2,}$)");
  return std::regex_match(email, re);
}

bool validate_student(const Student& s, std::string& error) {
  if (!is_positive_id(s.id)) {
    error = "ID must be a positive integer.";
    return false;
  }
  if (s.name.empty() || s.surname.empty() || s.department.empty()) {
    error = "Name, surname and department cannot be empty.";
    return false;
  }
  if (!is_valid_email(s.email)) {
    error = "Invalid email format.";
    return false;
  }
  error.clear();
  return true;
}
