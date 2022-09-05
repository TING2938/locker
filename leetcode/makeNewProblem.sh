#!/usr/bin/env bash

if [[ $# < 1 ]]; then
    echo "please input your problem name"
    exit
fi

cp template.cpp ${1}.cpp
sed -i "s/ProblemName/${1}/g" ${1}.cpp