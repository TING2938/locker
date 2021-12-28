package main

import (
	"flag"
	"context"
	pb "grpc_test/MySum"
	"log"
	"net"

	"google.golang.org/grpc"
)

var address = flag.String("addr", "localhost:50053", "address for this server")

type server struct{}

func (s *server) MyAdd(ctx context.Context, request *pb.DataRequest) (*pb.DataReply, error) {
	log.Printf("Received: %d, %d, %s", request.A, request.B, request.Msg)
	return &pb.DataReply{C: request.A + request.B}, nil
}

func main() {
	flag.Parse()
	lis, err := net.Listen("tcp", *address)
	if err != nil {
		log.Fatalf("failed to listen: %v", err)
	}
	s := grpc.NewServer()
	pb.RegisterAddServiceServer(s, &server{})
	log.Printf("server listening at %v", lis.Addr())
	if err := s.Serve(lis); err != nil {
		log.Fatalf("failed to serve: %v", err)
	}
}
