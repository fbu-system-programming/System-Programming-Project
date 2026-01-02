#include <iostream>
#include "validation.hpp"

static void expect(bool cond, const char* msg) {
  if (!cond) {
    std::cerr << "TEST FAILED: " << msg << "\n";
    std::exit(1);
  }
}

int main() {
  expect(is_positive_id(1), "positive id should pass");
  expect(!is_positive_id(0), "zero id should fail");
  expect(is_valid_email("a@b.com"), "simple email should pass");
  expect(!is_valid_email("wrong_mail"), "invalid email should fail");

  Student s{1,"Ahmet","Sencay","CENG","ahmet@example.com"};
  std::string err;
  expect(validate_student(s, err), "valid student should pass");
  s.email = "bad";
  expect(!validate_student(s, err), "invalid student should fail");

  std::cout << "OK\n";
  return 0;
}
