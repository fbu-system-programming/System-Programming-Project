# Installation Guide (INSTALL.md)

This document explains how to set up and run the **Student Information System (SIS)** project.

The system runs as **two Docker containers**:

* **PostgreSQL database** container (`sis_db`)
* **C++ SIS application** container (`sis_app`)
  (built with **CMake**, connects to PostgreSQL via **libpqxx**)

> Requirement: `docker compose` must be able to start both containers successfully.

---

## 1) Prerequisites

Install the following on your machine:

* **Git**
* **Docker**
* **Docker Compose** (Docker Desktop includes Docker + Compose)

Optional (only if you want to build locally outside Docker):

* **CMake** + a C++ compiler (e.g., g++)

---

## 2) Clone the repository

Clone the repository and open the project folder.

### Option A — GitHub Desktop (recommended if you avoid terminal)

1. Open **GitHub Desktop**
2. Click **File → Clone repository**
3. Select the repository and choose a local path
4. Click **Clone**
5. Open the cloned folder

### Option B — Terminal (optional)

git clone <repo-url>
cd System-Programming-Project

---

## 3) Environment variables (.env)

This project uses environment variables for database configuration.

### Create `.env` from `.env.example`

1. In the repository root, find: `.env.example`
2. Create a new file named: `.env`
3. Copy the content of `.env.example` into `.env`
4. Adjust values if needed

**Important**

* Do **NOT** commit `.env`
* Commit only `.env.example`

---

## 4) Run with Docker Compose (recommended)

From the repository root (same folder where `docker-compose.yml` exists):

### Step A — Build & start containers

docker compose up -d --build

### Step B — Verify containers

docker compose ps

**Expected**

* `sis_db` is **healthy**
* `sis_app` is **running**

If `sis_db` is not healthy, check logs:

docker compose logs db

---

## 5) Run the application

Run the SIS application inside the `app` container:

docker compose exec app /app/sis_app

The program provides a simple menu to:

* Add student
* List students
* Update student
* Delete student

### Notes

* Student `id` must be a positive integer
* Email must be a valid format
* The database schema is initialized automatically via the SQL script under `db/init/`

---

## 6) Stop / reset

### Stop containers

docker compose down

### Stop and remove volumes (deletes database data)

docker compose down -v

---

## 7) Troubleshooting

### “could not translate host name 'db'”

* This usually happens when the app is run outside the compose network.
* Make sure you run the app using:

docker compose exec app /app/sis_app

### DB not ready yet

* Wait a few seconds and try again.
* Check status:

docker compose ps

### Check logs (db/app)

docker compose logs db
docker compose logs app

### Port conflicts

* If PostgreSQL port is already used on your machine, change the port mapping in `docker-compose.yml` (if a port mapping exists).
* If there is no port mapping, PostgreSQL is only accessible inside the Docker network, which avoids conflicts by default.

### Reset everything (clean start)

docker compose down -v
docker compose up -d --build
