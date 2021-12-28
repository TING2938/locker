import grpc
from mySum.helloworld_pb2 import DataRequest
from mySum.helloworld_pb2_grpc import AddServiceStub

def run():
    with grpc.insecure_channel('localhost:50001') as channel:
        stub = AddServiceStub(channel=channel)
        respose = stub.myAdd(DataRequest(a=2, b=3, msg="from python"))

    print(f"Hello client reveived: {respose.c}")

if __name__ == "__main__":
    run()
    
