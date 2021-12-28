#include <cstdio>
#include <memory>

#include <grpcpp/grpcpp.h>

#include "mySum/helloworld.grpc.pb.h"

using Int = google::protobuf::int32;

class AddClient
{
public:
    AddClient(std::shared_ptr<grpc::Channel> channel) : stub_(rpc_package::AddService::NewStub(channel)) {}

    Int myAdd(Int a, Int b, const std::string& msg)
    {
        rpc_package::DataRequest request;
        request.set_a(a);
        request.set_b(b);
        request.set_msg(msg);

        rpc_package::DataReply reply;

        grpc::ClientContext context;

        auto status = stub_->myAdd(&context, request, &reply);
        if (status.ok())
        {
            return reply.c();
        } else {
            std::cout << status.error_code() << ": " << status.error_message() << std::endl; 
            return -1;
        }
    }
private:
    std::unique_ptr<rpc_package::AddService::Stub> stub_;
};

int main(int argc, char** argv)
{
    AddClient adder(grpc::CreateChannel("localhost:50001", grpc::InsecureChannelCredentials()));
    Int c = adder.myAdd(6, 3, "C++");
    std::cout << "Result: " << c << std::endl;
}
