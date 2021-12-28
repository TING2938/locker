from concurrent import futures
import grpc
import logging

from mySum.helloworld_pb2_grpc import add_AddServiceServicer_to_server, AddServiceServicer
from mySum.helloworld_pb2 import DataReply

class Hello(AddServiceServicer):
    # define the interface
    def myAdd(self, request, context):
        logging.info(f"receive request, a={request.a}, b={request.b}, msg={request.msg}")
        return DataReply(c=request.a + request.b)

def serve():
    # use thread pool to deal with the tasks of server
    server = grpc.server(thread_pool=futures.ThreadPoolExecutor(max_workers=10))

    # add tasks function to rpc server
    add_AddServiceServicer_to_server(servicer=Hello(), server=server)

    server.add_insecure_port('localhost:50001')
    server.start()
    server.wait_for_termination()
    
if __name__ == "__main__":
    logging.basicConfig(level=logging.INFO, format="%(asctime)s - %(message)s", datefmt="%m/%d/%Y %H:%M:%S %p")
    serve()



