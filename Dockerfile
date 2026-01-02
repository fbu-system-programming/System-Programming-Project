# ---- build stage ----
FROM ubuntu:22.04 AS build

WORKDIR /app

RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \
    cmake \
    pkg-config \
    libpq-dev \
    libpqxx-dev \
    ca-certificates \
 && rm -rf /var/lib/apt/lists/*

COPY . .

RUN cmake -S . -B build -DCMAKE_BUILD_TYPE=Release && cmake --build build --config Release

# ---- runtime stage ----
FROM ubuntu:22.04

WORKDIR /app

# runtime only: shared libs for libpqxx/libpq
RUN apt-get update && apt-get install -y --no-install-recommends \
    libpq5 \
    libpqxx-dev \
    ca-certificates \
 && rm -rf /var/lib/apt/lists/*

# Copy binary from build stage (handle both possible output paths)
COPY --from=build /app/build/main /app/main
COPY --from=build /app/build/src/main /app/main

CMD ["/app/main"]
