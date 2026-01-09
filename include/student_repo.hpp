#pragma once
#include <string>
#include <vector>
#include <pqxx/pqxx>

#include "student.hpp"

class StudentRepository {
public:
  explicit StudentRepository(pqxx::connection& c);

  void ensure_schema();                 // optional safety (creates table if missing)
  void add_student(const Student& s);   // CREATE
  std::vector<Student> list_students(); // READ
  bool update_student(const Student& s);// UPDATE (by id)
  bool delete_student(int id);          // DELETE (by id)

private:
  pqxx::connection& conn;
};
