FROM ubuntu:18.04

ENV PipProxy="-i http://10.153.3.130/pypi/web/simple --trusted-host 10.153.3.130"
ENV USER_NAME="y26264"
ENV NEW_PASSWORD="yt%402938"

# for sshd server
RUN echo "deb http://mirrors.aliyun.com/ubuntu/ focal main restricted universe multiverse" > /etc/apt/sources.list && \
	echo "deb-src http://mirrors.aliyun.com/ubuntu/ focal main restricted universe multiverse" >> /etc/apt/sources.list && \
	echo "deb http://mirrors.aliyun.com/ubuntu/ focal-security main restricted universe multiverse" >> /etc/apt/sources.list && \
	echo "deb-src http://mirrors.aliyun.com/ubuntu/ focal-security main restricted universe multiverse" >> /etc/apt/sources.list && \
	echo "deb http://mirrors.aliyun.com/ubuntu/ focal-updates main restricted universe multiverse" >> /etc/apt/sources.list && \
	echo "deb-src http://mirrors.aliyun.com/ubuntu/ focal-updates main restricted universe multiverse" >> /etc/apt/sources.list && \
	echo "deb http://mirrors.aliyun.com/ubuntu/ focal-proposed main restricted universe multiverse" >> /etc/apt/sources.list && \
	echo "deb-src http://mirrors.aliyun.com/ubuntu/ focal-proposed main restricted universe multiverse" >> /etc/apt/sources.list && \
	echo "deb http://mirrors.aliyun.com/ubuntu/ focal-backports main restricted universe multiverse" >> /etc/apt/sources.list && \
	echo "deb-src http://mirrors.aliyun.com/ubuntu/ focal-backports main restricted universe multiverse" >> /etc/apt/sources.list && \
	apt-get update && \
	apt-get install -y openssh-server && \
	mkdir /var/run/sshd && \
	echo 'root:root' |chpasswd && \
	sed -ri 's/^#?PermitRootLogin\s+.*/PermitRootLogin yes/' /etc/ssh/sshd_config && \
	sed -ri 's/UsePAM yes/#UsePAM yes/g' /etc/ssh/sshd_config && \
	apt-get clean && \
 	rm -rf /var/lib/apt/lists/* /tmp/* /var/tmp/*

# for proxy
RUN echo 'export no_proxy=localhost,apiserver.k8s.com,127.0.0.0/8,192.0.0.0/8,172.0.0.0/8,10.0.0.0/8' >> /etc/profile && \
	echo 'export http_proxy=http://'$USER_NAME':'$NEW_PASSWORD'@172.25.14.129:8080' >> /etc/profile && \
	echo 'export https_proxy=http://'$USER_NAME':'$NEW_PASSWORD'@172.25.14.129:8080' >> /etc/profile && \
	echo '=============WGET SET PROXY=============' && \
	echo 'use_proxy = on' > /etc/wgetrc && \
	echo 'http_proxy = http://'$USER_NAME':'$NEW_PASSWORD'@172.25.14.129:8080' >> /etc/wgetrc && \
	echo 'ftp_proxy = http://'$USER_NAME':'$NEW_PASSWORD'@172.25.14.129:8080' >> /etc/wgetrc && \
	echo '=============APT SET PROXY=============' && \
	echo 'Acquire::http::proxy "http://'$USER_NAME':'$NEW_PASSWORD'@172.25.14.129:8080/";'  >> /etc/apt/apt.conf && \
	echo 'Acquire::https::proxy "http://'$USER_NAME':'$NEW_PASSWORD'@172.25.14.129:8080/";'  >> /etc/apt/apt.conf

###############################################################################################
WORKDIR /work

### for C++ Python and Golang
RUN apt update && apt-get install -y vim \
    build-essential autoconf git pkg-config automake libtool curl make cmake libz-dev g++ unzip \ 
    python3 python3-pip && \ 
    apt clean

###### C++, install protobuf first, then grpc
RUN git clone https://gitee.com/mirrors/grpc.git /var/local/git/grpc && \
    cd /var/local/git/grpc && \
    git submodule update --init && \
    echo "--- installing protobuf ---" && \
    cd third_party/protobuf && \
    ./autogen.sh && ./configure --enable-shared && \
    make -j && make install && make clean && ldconfig && \
    echo "--- installing grpc ---" && \
    cd /var/local/git/grpc && \
    mkdir build && cd build && cmake .. && make -j && make install && make clean && ldconfig && \
    rm -rf /var/local/git/grpc/*

###### Python
RUN pip3 install grpcio==1.27.2 grpcio-tools==1.27.2 ${PipProxy} 

###### Golang
COPY go1.17.1.linux-amd64.tar.gz . 
RUN tar -C /usr/local -xzf go1.17.1.linux-amd64.tar.gz && \
    rm -rf go1.17.1.linux-amd64.tar.gz && \
    echo 'export GOROOT=/usr/local/go' >> /root/.bashrc && \ 
    echo 'export GOPATH=/root/go' >> /root/.bashrc && \ 
    echo 'export GOBIN=$GOPATH/bin' >> /root/.bashrc && \
    echo 'export PATH=$GOROOT/bin:$PATH' >> /root/.bashrc && \
    echo 'export PATH=$GOPATH/bin:$PATH' >> /root/.bashrc && \
    echo 'export GO111MODULE=on' >> /root/.bashrc && \
    echo 'export GOPROXY=https://goproxy.cn,direct' >> /root/.bashrc 


###############################################################################################

CMD    ["/usr/sbin/sshd", "-D"]



### build and run docker
# docker build -t yt_docker_sshd .
# docker run -d -p 2922:22 -v $(pwd):/work -v /root/.ssh:/root/.ssh yt_docker_sshd

### ssh it
# ssh root@10.227.4.32 -p 2922




