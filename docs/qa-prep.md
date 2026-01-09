# Week 4 Q&A Preparation (SIS Project)

Below are likely questions and short answers for the final presentation/demo.

---

## 1) What does your project do?
It is a Student Information System (SIS) written in C++ that performs CRUD operations on a PostgreSQL database. The entire system runs with Docker Compose for reproducible setup.

## 2) Why did you choose Docker / Docker Compose?
To ensure the project runs the same way on every machine, simplify setup, and manage the database + application together with one command.

## 3) What are the containers in your setup?
- sis_db: PostgreSQL database container
- sis_app: C++ application container (built with CMake, connects using libpqxx)

## 4) How does the C++ application connect to PostgreSQL?
It uses libpqxx (C++ client library) and connection parameters are provided via environment variables (from docker-compose.yml / .env).

## 5) Where is the database schema created?
Under db/init (SQL scripts). PostgreSQL runs these scripts on first initialization.

## 6) What CRUD operations do you support?
Create student, list students, update student fields, delete student.

## 7) How do you ensure the database is ready before the app runs?
docker-compose.yml uses a healthcheck for PostgreSQL and the app service depends on the db service being healthy.

## 8) What CI do you have?
GitHub Actions runs CMake configure/build and unit tests (ctest). The workflow must be green before merging PRs.

## 9) What tests do you have?
Unit tests for validation logic (and any other test cases added in tests/). Tests are executed via ctest in CI.

## 10) How do you verify the project works end-to-end?
By starting Docker Compose and running the application inside the container, then performing a CRUD demo (add/list/update/delete).

## 11) How do you handle invalid input?
Validation logic checks inputs (e.g., empty strings / format constraints depending on implementation). Invalid inputs are rejected with a clear message.

## 12) What is your branching / collaboration strategy?
GitFlow-like approach:
- develop is the integration branch
- feature/* branches for work
- PRs into develop
- At least 1 approving review before merge

## 13) How do you ensure there are no memory leaks?
We keep code simple and RAII-friendly (std::string, std::vector, smart pointers when needed). If required, we can verify with tools like Valgrind in a controlled environment.

## 14) What evidence do you show to the instructor?
- GitHub Actions green (build + tests)
- docker compose ps showing healthy/running containers
- Live CRUD demo via docker compose exec app /app/sis_app
