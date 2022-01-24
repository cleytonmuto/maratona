#!/bin/bash
g++ F.cpp -o F
for (( i=1; i <= 33 ; i++ ))
do
    ./F < input/F_$i > output/F_$i.out
    diff output/F_$i output/F_$i.out
done

