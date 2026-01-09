# Week 4 Demo Script (Student Information System - SIS)

Goal: Demonstrate that the project runs in Docker Compose, connects to PostgreSQL, and performs CRUD operations via the C++ SIS application.

Estimated duration: 4–6 minutes

---

## 0) What we will show (quick overview)
- Repo workflow (develop + feature branches + PR reviews)
- GitHub Actions: CI (CMake build + tests) is green
- Docker Compose starts 2 containers:
  - sis_db (PostgreSQL)
  - sis_app (C++ SIS application container)
- Live CRUD demo inside the app container

---

## 1) Start the system with Docker Compose
From the repository root:

1) Build & start containers:
   docker compose up -d --build

2) Verify services:
   docker compose ps

Expected:
- sis_db is "healthy"
- sis_app is "running"

---

## 2) Run the C++ SIS application inside the container
Run:
docker compose exec app /app/sis_app

Expected:
- A simple menu is displayed (CRUD options)

---

## 3) CRUD demonstration scenario
Use a consistent example record.

### A) CREATE (Add student)
- Choose "Add student"
- Example input:
  Name: Ahmet
  Surname: Sencay
  Department: Computer Engineering
  Email: ahmet@example.com

Expected:
- "Student added successfully" (or similar confirmation)

### B) READ (List students)
- Choose "List students"

Expected:
- The new student appears in the list with the provided fields

### C) UPDATE (Update student)
- Choose "Update student"
- Select the student (by ID if requested)
- Update Department to:
  Software Engineering

Expected:
- Update confirmation message
- Listing again shows the updated department

### D) DELETE (Delete student)
- Choose "Delete student"
- Select the same student (by ID if requested)

Expected:
- Delete confirmation message
- Listing again shows the student is removed

---

## 4) Evidence to mention during demo
- GitHub Actions CI is passing (build + unit tests)
- The system is containerized and reproducible via Docker Compose
- PostgreSQL is initialized via db/init scripts

---

## 5) Stop / cleanup (optional)
To stop:
docker compose down

To reset database data:
docker compose down -v
