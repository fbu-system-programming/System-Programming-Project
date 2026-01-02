#include <iostream>
#include <limits>
#include <pqxx/pqxx>

#include "db_config.hpp"
#include "student_repo.hpp"
#include "validation.hpp"

static void clear_stdin() {
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

static Student read_student_from_user() {
  Student s;

  std::cout << "ID: ";
  std::cin >> s.id;
  clear_stdin();

  std::cout << "Name: ";
  std::getline(std::cin, s.name);

  std::cout << "Surname: ";
  std::getline(std::cin, s.surname);

  std::cout << "Department: ";
  std::getline(std::cin, s.department);

  std::cout << "Email: ";
  std::getline(std::cin, s.email);

  return s;
}

int main() {
  try {
    DbConfig cfg = load_db_config_from_env();
    pqxx::connection conn(make_conninfo(cfg));
    StudentRepository repo(conn);

    // optional safety: ensure table exists even if init script not mounted
    repo.ensure_schema();

    while (true) {
      std::cout << "\n=== Student Information System ===\n";
      std::cout << "1) Add student\n";
      std::cout << "2) List students\n";
      std::cout << "3) Update student\n";
      std::cout << "4) Delete student\n";
      std::cout << "0) Exit\n";
      std::cout << "Select: ";

      int choice = -1;
      std::cin >> choice;
      clear_stdin();

      if (choice == 0) break;

      if (choice == 1) {
        Student s = read_student_from_user();
        std::string err;
        if (!validate_student(s, err)) {
          std::cerr << "Validation error: " << err << "\n";
          continue;
        }
        repo.add_student(s);
        std::cout << "OK: student added.\n";
      } else if (choice == 2) {
        auto list = repo.list_students();
        std::cout << "\n--- Students (" << list.size() << ") ---\n";
        for (const auto& s : list) {
          std::cout << s.id << " | " << s.name << " " << s.surname
                    << " | " << s.department << " | " << s.email << "\n";
        }
      } else if (choice == 3) {
        Student s = read_student_from_user();
        std::string err;
        if (!validate_student(s, err)) {
          std::cerr << "Validation error: " << err << "\n";
          continue;
        }
        bool ok = repo.update_student(s);
        std::cout << (ok ? "OK: updated.\n" : "Not found: no row updated.\n");
      } else if (choice == 4) {
        int id;
        std::cout << "ID to delete: ";
        std::cin >> id;
        clear_stdin();
        if (!is_positive_id(id)) {
          std::cerr << "Validation error: ID must be positive.\n";
          continue;
        }
        bool ok = repo.delete_student(id);
        std::cout << (ok ? "OK: deleted.\n" : "Not found: no row deleted.\n");
      } else {
        std::cout << "Invalid choice.\n";
      }
    }

    std::cout << "Bye.\n";
    return 0;
  } catch (const std::exception& ex) {
    std::cerr << "Fatal error: " << ex.what() << "\n";
    return 1;
  }
}
