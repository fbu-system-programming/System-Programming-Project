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

RUN cmake -S . -B build -DCMAKE_BUILD_TYPE=Release \
 && cmake --build build --config Release

# Copy app binary to a stable path for the runtime stage
RUN mkdir -p /out && cp build/sis_app /out/sis_app

# ---- runtime stage ----
FROM ubuntu:22.04

WORKDIR /app

# runtime libs (safe option: install libpqxx-dev, avoids versioned package-name issues)
RUN apt-get update && apt-get install -y --no-install-recommends \
    libpq5 \
    libpqxx-dev \
    ca-certificates \
 && rm -rf /var/lib/apt/lists/*

COPY --from=build /out/sis_app /app/sis_app

CMD ["/app/sis_app"]
