# System Programming Project

![CI](https://github.com/fbu-system-programming/System-Programming-Project/actions/workflows/ci.yml/badge.svg?branch=develop)

This project is developed as part of the System Programming course.

## Project Objective
The objective of this project is to gain hands-on experience in system programming concepts, collaborative software development,
containerization, and CI/CD practices using modern tools.

From **Week 3**, the project includes a C++ Student Information System (SIS) that connects to PostgreSQL using **libpqxx** and is built with **CMake**.

## Technologies
- Ubuntu
- C++
- CMake
- PostgreSQL
- libpqxx
- Docker
- Docker Compose
- Git & GitHub

## Project Structure
- `src/` : C++ source files
- `include/` : Header files
- `tests/` : Unit tests (CTest)
- `db/init/` : DB init SQL scripts
- `docs/` : Documentation and Evidances
- `.github/workflows/` : CI workflows

## Development Workflow
- Feature branches are created from `develop`
- Pull requests are reviewed before merging
- Direct commits to `main` and `develop` are restricted

## Docker Images (Docker Hub)

- PostgreSQL Image: https://hub.docker.com/r/mertalimirzanli/fbu-220304031-system-programming-project-postgres
- Application Image: https://hub.docker.com/r/mertalimirzanli/fbu-220304031-system-programming-project-app

Images are public and accessible on Docker Hub.
docker compose runs successfully end-to-end with the final images.

### Image Tags
- `latest`
- `v0.1.0`

## Running (Week 3 - Docker Compose)


> Terminal:
```bash
docker compose up -d --build
docker compose ps
docker compose exec app /app/sis_app
```
### Expected
- `sis_db` should be **healthy**
- `sis_app` should be **running**
- The SIS application menu should appear when running   
- Inside the application, basic CRUD operations can be verified:  
Add student  
List students  
Update student  
Delete student  


