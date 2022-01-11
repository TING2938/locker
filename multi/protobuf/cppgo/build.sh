

rm *.so

g++ hi.cpp *.cc -fPIC -shared `pkg-config --cflags --libs protobuf` -o libhi.so


