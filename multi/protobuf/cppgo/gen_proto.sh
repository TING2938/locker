#!/usr/bin/env bash

protoDir="./"

cpp_outDir="./ccode"
go_outDir="./"

protoc -I ${protoDir} ${protoDir}/*.proto --cpp_out=${cpp_outDir}

protoc -I ${protoDir} ${protoDir}/*.proto --go_out=${go_outDir}