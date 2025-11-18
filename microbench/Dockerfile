FROM toolmanp/ubuntu:22.04-zpoline AS builder
RUN apt update && apt upgrade -y
RUN apt install build-essential -y
RUN apt clean
WORKDIR /build
ADD . .
RUN make

FROM toolmanp/ubuntu:22.04-zpoline
COPY --from=builder /build/* /usr/local/bin/
