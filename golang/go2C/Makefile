

CXX = g++ 
LD = ld 

all : cppcode  

golib:
	go build -o libtest.a -buildmode=c-archive gocode.go 

cppcode:
	$(CXX) cppcode.cpp ./libtest.a -pthread -o cppcode
