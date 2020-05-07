FROM centos

RUN yum install bash -y 
RUN yum install git -y 
RUN yum install gcc -y
RUN yum install gcc-c++ -y
RUN yum install python3 -y

WORKDIR /home/app/

RUN git clone https://github.com/KristyAvsievich/Laba4_SP.git \
	&& cd Laba4_SP/ \
	&& g++ 4_first.cpp -o 4first \
	&& g++ 4_second.cpp -o 4second -lstdc++fs

WORKDIR /home/app/Laba4_SP/
