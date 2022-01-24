#!/bin/bash
g++ D.cpp -o D
for (( i=1; i <= 17; i++ ))
do
    ./D < input/D_$i > output/D_$i.out
    diff output/D_$i output/D_$i.out
done
