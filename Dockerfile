FROM ubuntu:22.04

WORKDIR /app

RUN apt-get update && apt-get install -y --no-install-recommends \
    ca-certificates \
    build-essential \
    cmake \
 && rm -rf /var/lib/apt/lists/*

COPY . .

# Build the minimal C++ app (Week 2)
RUN cmake -S . -B build && cmake --build build

# Run once (prints message), then keep container alive for Week 2 compose demo
CMD ["bash", "-lc", "./build/main && sleep infinity"]
