# User Manual (MANUAL.md)

## Overview
This repository contains the **Student Information System (SIS)** project for the System Programming course.

The system runs with **Docker Compose** as two containers:
- **PostgreSQL database** container (`sis_db`)
- **C++ SIS application** container (`sis_app`) built with **CMake** and connected via **libpqxx**

> Note: The application is executed inside the `app` service container.

---

## Requirements
You need:
- Git
- Docker
- Docker Compose (Docker Desktop includes it)

---

## Quick Start (Recommended)
1) Clone the repository (GitHub Desktop is fine).
2) From the repository root (where `docker-compose.yml` exists), start services:

docker compose up -d --build

3) Verify containers:

docker compose ps

Expected:
- `sis_db` is **healthy**
- `sis_app` is **running**

---

## Running the Application
Run the application inside the `app` container:

docker compose exec app /app/sis_app

If you see database connection issues, wait a few seconds and try again (DB may still be initializing).

---

## What the Program Does
The SIS application provides a simple **CRUD** menu for **students**.

Typical options include:
- Add student
- List students
- Update student
- Delete student
- Exit

> The exact menu text may differ slightly, but the actions above are supported.

---

## Student Data Model (High-level)
A student record includes:
- id (primary key)
- name
- surname
- department
- email (unique)

---

## Example Demo Flow (For Presentation)
1) Start containers:
docker compose up -d --build

2) Run the app:
docker compose exec app /app/sis_app

3) Add a student:
- name: Ahmet
- surname: Sencay
- department: Computer Engineering
- email: ahmet@example.com

4) List students (verify the inserted record)

5) Update student (change department or surname)

6) Delete student

---

## Troubleshooting

### 1) “could not translate host name 'db'”
This usually happens when the app is run outside Docker Compose network.
Always run via:
docker compose exec app /app/sis_app

### 2) DB not ready yet / connection refused
- Wait a few seconds.
- Check:
docker compose ps

### 3) Container is not running
Rebuild and start again:
docker compose up -d --build

### 4) Reset database (delete data)
Stop and remove volumes:
docker compose down -v

---

## Notes
- `INSTALL.md` explains installation/setup steps.
- Unit tests are executed in GitHub Actions CI.
- Docker images are published to Docker Hub (see README for links).
