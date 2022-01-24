#!/bin/bash
g++ K.cpp -o K
for (( i=1; i <= 38 ; i++ ))
do
    ./K < input/K_$i > output/K_$i.out
    diff output/K_$i output/K_$i.out
done
