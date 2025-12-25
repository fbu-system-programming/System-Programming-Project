# ---- build stage ----
FROM ubuntu:22.04 AS build
WORKDIR /app

RUN apt-get update && apt-get install -y \
    build-essential cmake pkg-config \
    libpqxx-dev libpq-dev \
 && rm -rf /var/lib/apt/lists/*

COPY . .
RUN cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
RUN cmake --build build -j

# ---- runtime stage ----
FROM ubuntu:22.04
WORKDIR /app

RUN apt-get update && apt-get install -y \
    ca-certificates \
 && rm -rf /var/lib/apt/lists/*

# build klasörünü kopyalama
COPY --from=build /app/build /app/build

# CMake binary’i build içinde bir yere koyar. Şimdilik container ayakta kalsın:
CMD ["bash", "-lc", "echo 'Image ready. Use docker compose exec app ...' && sleep infinity"]
