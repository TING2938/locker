#include <libipc/ipc.h>
#include <iostream>

int main(int argc, char** argv) 
{
    std::string channelName = "testChannel";

    std::string mode{ argv[1] };
    if (mode == "send") 
    {
        ipc::channel channel(channelName.c_str(), ipc::sender);
        std::string buffer;
        while (std::cin >> buffer) {
            if (buffer.empty()) break;
            std::cout << "start send ...\n";
            channel.send(buffer);
            std::cout << "send finished\n";
            buffer.clear();
        }
    }
    else if (mode == "recv") 
    {
        ipc::channel channel(channelName.c_str(), ipc::receiver);
        while (true) {
            std::cout << "start recv ... \n";
            auto buf = channel.recv(10000);
            std::cout << "recv finished\n";
            std::string data{ buf.get<const char*>(), buf.size()-1};
            std::cout << "recv: " << data << std::endl;
        }
    }
    return 0;
}