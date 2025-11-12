FROM toolmanp/ubuntu:22.04-zpoline

ENV DEBIAN_FRONTEND=noninteractive
RUN apt update && apt upgrade -y
RUN apt install iperf3 netperf fio redis memcached
RUN rm -rf /var/cache/apt/archives /var/lib/apt/lists/*
