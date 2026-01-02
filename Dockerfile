# ---- build stage ----
FROM ubuntu:22.04 AS build

WORKDIR /app

RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    libpqxx-dev \
    ca-certificates \
 && rm -rf /var/lib/apt/lists/*

COPY . .

RUN cmake -S . -B build && cmake --build build

# ---- runtime stage ----
FROM ubuntu:22.04

WORKDIR /app

RUN apt-get update && apt-get install -y \
    libpqxx-6-4 \
    ca-certificates \
 && rm -rf /var/lib/apt/lists/*

COPY --from=build /app/build/main /app/main

CMD ["/app/main"]
