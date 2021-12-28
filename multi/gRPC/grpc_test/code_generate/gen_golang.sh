#!/usr/bin/env bash

protoDir="../protos"
outDir="../languages/golang"
protoc -I ${protoDir} ${protoDir}/*.proto --go_out=plugins=grpc:${outDir}
