#!/usr/bin/env bash

protoDir="../protos"
outDir="../languages/python/mySum"

python3 -m grpc_tools.protoc -I ${protoDir} --python_out=${outDir} --grpc_python_out=${outDir} ${protoDir}/*.proto