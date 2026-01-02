#include "db_config.hpp"
#include <cstdlib>

static std::string env_or(const char* key, const std::string& def) {
  const char* v = std::getenv(key);
  return (v && *v) ? std::string(v) : def;
}

DbConfig load_db_config_from_env() {
  DbConfig cfg;
  cfg.host     = env_or("DB_HOST", cfg.host);
  cfg.port     = env_or("DB_PORT", cfg.port);
  cfg.dbname   = env_or("DB_NAME", cfg.dbname);
  cfg.user     = env_or("DB_USER", cfg.user);
  cfg.password = env_or("DB_PASSWORD", cfg.password);
  return cfg;
}

std::string make_conninfo(const DbConfig& cfg) {
  return "host=" + cfg.host +
         " port=" + cfg.port +
         " dbname=" + cfg.dbname +
         " user=" + cfg.user +
         " password=" + cfg.password;
}
