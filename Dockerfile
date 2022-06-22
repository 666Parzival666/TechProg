#FROM ubuntu
FROM ubuntu:16.04 
COPY . /usr/src/myapp
WORKDIR /usr/src/myapp
RUN apt update 
RUN DEBIAN_FRONTEND=noninteractive apt-get -y install qt5-default
RUN apt -y install build-essential
RUN qmake echoServer.pro
RUN make
CMD ["qmake", "echoServer.pro"]
CMD ["make"]
CMD ["./echoServer"]
