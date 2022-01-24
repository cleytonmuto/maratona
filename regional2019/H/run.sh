#!/bin/bash
g++ H.cpp -o H
for (( i=1; i <= 22; i++ ))
do
    ./H < input/H_$i > output/H_$i.out
    diff output/H_$i output/H_$i.out
done
