
#include <cstdio>
#include <memory>

#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>

#include "mySum/helloworld.grpc.pb.h"

class MyAddServiceImpl : public rpc_package::AddService::Service
{
    grpc::Status myAdd(grpc::ServerContext *context, const rpc_package::DataRequest *request, rpc_package::DataReply *reply) override
    {
        std::printf("service: a=%d, b=%d, msg=%s\n", request->a(), request->b(), request->msg().c_str());
        reply->set_c(request->a() + request->b());
        return grpc::Status::OK;
    }
};

void RunServer()
{
    std::string server_address = "localhost:50001";
    MyAddServiceImpl service;

    grpc::EnableDefaultHealthCheckService(true);
    grpc::reflection::InitProtoReflectionServerBuilderPlugin();

    grpc::ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);

    std::unique_ptr<grpc::Server> server(builder.BuildAndStart());

    std::printf("Server listening on %s\n", server_address.c_str());

    server->Wait();
}

int main(int argc, char **argv)
{
    RunServer();
}
