#include "student_repo.hpp"

StudentRepository::StudentRepository(pqxx::connection& c) : conn(c) {}

void StudentRepository::ensure_schema() {
  pqxx::work tx(conn);
  tx.exec(R"(
    CREATE TABLE IF NOT EXISTS students (
      id          INTEGER PRIMARY KEY,
      name        VARCHAR(60)  NOT NULL,
      surname     VARCHAR(60)  NOT NULL,
      department  VARCHAR(120) NOT NULL,
      email       VARCHAR(120) NOT NULL UNIQUE
    );
  )");
  tx.commit();
}

void StudentRepository::add_student(const Student& s) {
  pqxx::work tx(conn);
  tx.exec_params(
    "INSERT INTO students (id, name, surname, department, email) VALUES ($1,$2,$3,$4,$5)",
    s.id, s.name, s.surname, s.department, s.email
  );
  tx.commit();
}

std::vector<Student> StudentRepository::list_students() {
  pqxx::read_transaction tx(conn);
  auto r = tx.exec("SELECT id, name, surname, department, email FROM students ORDER BY id ASC");

  std::vector<Student> out;
  out.reserve(r.size());
  for (const auto& row : r) {
    Student s;
    s.id = row["id"].as<int>();
    s.name = row["name"].as<std::string>();
    s.surname = row["surname"].as<std::string>();
    s.department = row["department"].as<std::string>();
    s.email = row["email"].as<std::string>();
    out.push_back(std::move(s));
  }
  return out;
}

bool StudentRepository::update_student(const Student& s) {
  pqxx::work tx(conn);
  auto r = tx.exec_params(
    "UPDATE students SET name=$2, surname=$3, department=$4, email=$5 WHERE id=$1",
    s.id, s.name, s.surname, s.department, s.email
  );
  tx.commit();
  return r.affected_rows() > 0;
}

bool StudentRepository::delete_student(int id) {
  pqxx::work tx(conn);
  auto r = tx.exec_params("DELETE FROM students WHERE id=$1", id);
  tx.commit();
  return r.affected_rows() > 0;
}
