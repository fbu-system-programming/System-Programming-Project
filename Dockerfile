FROM ubuntu:22.04
WORKDIR /app

RUN apt-get update && apt-get install -y ca-certificates \
 && rm -rf /var/lib/apt/lists/*

COPY . .

# Week 2: app henüz tam derlenmeyebilir; container ayakta kalsın
CMD ["bash", "-lc", "echo 'App image (Week2) ready. Build/run app in Week3.' && sleep infinity"]
