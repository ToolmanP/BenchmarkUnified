FROM toolmanp/ubuntu:22.04-zpoline AS builder
ENV DEBIAN_FRONTEND=noninteractive
RUN apt update && apt upgrade -y
RUN apt install libevent-dev libtbb2-dev build-essential cmake wget flex bison -y
ADD libmemcached libmemcached
WORKDIR /build
RUN cmake ../libmemcached -DCMAKE_BUILD_TYPE=Release
RUN make -j$(nproc)
RUN make install

FROM toolmanp/ubuntu:22.04-zpoline
ENV DEBIAN_FRONTEND=noninteractive
RUN apt update && apt upgrade -y
RUN apt install iperf3 netperf fio redis memcached mysql-server libevent-2.1-7 libtbb2 -y
RUN rm -rf /var/cache/apt/archives /var/lib/apt/lists/*
COPY --from=builder /usr/local/bin/* /usr/local/bin/
COPY --from=builder /usr/local/lib/* /usr/local/lib/
WORKDIR /ioperf
ADD . .
