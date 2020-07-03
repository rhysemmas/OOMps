# ======== build ======== #
FROM ubuntu:bionic as builder
# bionic = 18.04 LTS

RUN apt-get update && \
	apt-get install -y build-essential git cmake autoconf libtool pkg-config

WORKDIR /src

COPY main.cpp ./

RUN g++ -c -Wall main.cpp
RUN g++ -o oomps main.o -static

# ======== run ======== #
FROM alpine:3.12

WORKDIR /opt/hello-world

COPY --from=builder /src/oomps ./

CMD ["./oomps"]
