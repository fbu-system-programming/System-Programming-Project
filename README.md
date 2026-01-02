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
- `docs/` : Documentation
- `.github/workflows/` : CI workflows

## Development Workflow
- Feature branches are created from `develop`
- Pull requests are reviewed before merging
- Direct commits to `main` and `develop` are restricted

## Docker Images (Docker Hub)
> (Hocanın istediği iki link burada yer alır)

- PostgreSQL Image: https://hub.docker.com/r/mertalimirzanli/fbu-220304031-system-programming-project-postgres
- Application Image: https://hub.docker.com/r/mertalimirzanli/fbu-220304031-system-programming-project-app

### Image Tags
- `latest` : Latest stable image built via GitHub Actions
- `v0.1.0` : Initial Docker image version prepared for Week 2

## Running (Week 3 - Docker Compose)


> Terminal:
```bash
docker compose up -d --build
docker compose exec app /app/sis_app
