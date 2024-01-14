#!/usr/bin/env bash

if [[ $# < 2 ]]; then
    echo "please input your problem name and number"
    exit
fi

fnm=${2}.${1}.cpp
cp template.cpp ${fnm}
sed -i "s/ProblemName/${1}/g" ${fnm}
sed -i "s/ProblemNumber/${2}/g" ${fnm}
