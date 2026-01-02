-- Student Information System - initial schema (Week 3)
CREATE TABLE IF NOT EXISTS students (
  id          INTEGER PRIMARY KEY,
  name        VARCHAR(60)  NOT NULL,
  surname     VARCHAR(60)  NOT NULL,
  department  VARCHAR(120) NOT NULL,
  email       VARCHAR(120) NOT NULL UNIQUE
);

CREATE INDEX IF NOT EXISTS idx_students_department ON students(department);
