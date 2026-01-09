#pragma once
#include <string>

struct DbConfig {
  std::string host = "db";
  std::string port = "5432";
  std::string dbname = "students_db";
  std::string user = "postgres";
  std::string password = "postgres";
};

DbConfig load_db_config_from_env();
std::string make_conninfo(const DbConfig& cfg);
