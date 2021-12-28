#!/usr/bin/env bash

DST_DIR="./proto_out"
SRC_DIR="./"
protoc -I=$SRC_DIR --cpp_out=$DST_DIR data.proto