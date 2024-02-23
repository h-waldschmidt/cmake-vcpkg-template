FROM alpine:latest

RUN apk --no-cache add clang cmake ninja gdb

VOLUME [ "/app" ]
WORKDIR /app

ENTRYPOINT cmake --preset Debug && \
    cmake --build --preset Debug && \
    gdbserver :8000 /app/build/src/test-preoject