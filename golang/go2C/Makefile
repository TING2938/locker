

CXX = g++ 
LD = ld 

all : cppcode  

libtest.a: gocode.go
	go build -compiler gccgo -o $@ -buildmode=c-archive gocode.go 

cppcode: libtest.a
	$(CXX) cppcode.cpp ./libtest.a -L /usr/lib/gcc/x86_64-linux-gnu/10 -lgo -pthread -o cppcode
