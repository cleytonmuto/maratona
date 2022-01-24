#!/bin/bash
g++ B.cpp -o B
for (( i=1; i <= 22; i++ ))
do
    ./B < input/B_$i > output/B_$i.out
    diff output/B_$i output/B_$i.out
done
