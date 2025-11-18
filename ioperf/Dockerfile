FROM toolmanp/ubuntu:22.04-zpoline AS builder
ENV DEBIAN_FRONTEND=noninteractive
RUN apt update && apt upgrade -y
RUN apt install libevent-dev libtbb2-dev build-essential cmake wget flex bison -y
RUN wget https://github.com/awesomized/libmemcached/archive/refs/tags/1.1.4.tar.gz && tar -xvf 1.1.4.tar.gz
WORKDIR /build
RUN cmake ../libmemcached-1.1.4
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
