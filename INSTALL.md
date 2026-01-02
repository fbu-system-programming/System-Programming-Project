# Installation Guide

This document describes how to set up the project environment.

## Prerequisites
- Ubuntu Linux
- Docker
- Docker Compose
- Git

## Setup
1. Clone the repository.
2. Build and start the services using Docker Compose.
3. Run the application inside the container (to be implemented).

## CMake Build Verification (Week 2)

The project is configured to build using CMake with the following structure:
- src/
- include/
- tests/

The build is compatible with Docker-based workflows used in Week 2.


> Note: This guide will be expanded in later project phases.

## Week 3 – Run with Docker Compose


## Week 3 – Application Build and Execution

Starting from Week 3, the project includes a buildable C++ application integrated with PostgreSQL and managed via Docker.

### Build Process
- The C++ application is built using **CMake**.
- Source files are located under `src/` and headers under `include/`.
- The build process is executed inside a Docker container to ensure environment consistency.

### Running with Docker Compose
Docker Compose is used to orchestrate the application and database containers.

High-level workflow:
1. Docker images are built automatically (locally or via CI).
2. PostgreSQL container is started and initialized using scripts under `db/init/`.
3. The C++ application container is built and executed.

## Week 3 — Run with Docker Compose

### Option A (Minimal terminal)
```bash
docker compose up -d --build
docker compose exec app /app/sis_app

### Notes
- The application uses environment variables for database configuration.
- Unit tests are executed during the build process when applicable.
- CI pipelines verify successful build and execution on each pull request.

This installation guide will continue to be updated as the project evolves in later weeks.

1) Create a local `.env` file based on the template:

- Copy `.env.example` to `.env`
- Set `DOCKERHUB_USERNAME` to your Docker Hub username

2) Build and start services:

```bash
docker compose up -d --build
