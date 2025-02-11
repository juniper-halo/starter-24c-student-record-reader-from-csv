#include "solution.hpp"

#include <fstream>
#include <string>

Student ReadStudentRecFromStream(std::istream& is) {
  std::string first_name;
  std::string last_name;
  unsigned int uin = 0;
  double gpa = 0.0;
  char throw_away;

  is >> first_name;
  if (is.fail()) {
    return Student{};
  }

  is >> last_name;
  if (is.fail() || !(last_name.ends_with(","))) {
    return Student{};
  }

  is >> uin >> throw_away;
  if (is.fail() || throw_away != ',') {
    return Student{};
  }

  is >> gpa;
  if (is.fail()) {
    return Student{};
  }

  Student to_return;
  last_name.erase(last_name.length() - 1, 1);
  to_return.full_name = first_name + " " + last_name;
  to_return.uin = uin;
  to_return.gpa = gpa;

  return to_return;
}