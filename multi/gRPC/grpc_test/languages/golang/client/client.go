package main

import (
	"context"
	"fmt"
	pb "grpc_test/MySum"
	"log"
	"time"

	"google.golang.org/grpc"
)

func main() {
	conn, err := grpc.Dial("10.227.6.189:50053", grpc.WithInsecure(), grpc.WithBlock())
	if err != nil {
		log.Fatalf("did not connect: %v", err)
	}
	defer conn.Close()

	c := pb.NewAddServiceClient(conn)
	ctx, cancel := context.WithTimeout(context.Background(), time.Second)
	defer cancel()

	r, err := c.MyAdd(ctx, &pb.DataRequest{A: 1, B: 3, Msg: "Golang"})
	if err != nil {
		fmt.Printf("Conld not greet: %v", err)
	}
	fmt.Printf("result: %d\n", r.C)
}
