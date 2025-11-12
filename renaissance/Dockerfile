FROM toolmanp/ubuntu:22.04-zpoline
RUN apt update && apt upgrade -y
RUN apt install openjdk-21-jre curl -y
RUN apt clean
RUN curl -SL https://github.com/renaissance-benchmarks/renaissance/releases/download/v0.16.1/renaissance-gpl-0.16.1.jar -o renaissance-gpl.jar
ENTRYPOINT ["java", "-jar", "renaissance-gpl.jar"]
