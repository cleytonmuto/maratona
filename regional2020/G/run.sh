#!/bin/bash
g++ G.cpp -o G
for (( i=1; i <= 18 ; i++ ))
do
    ./G < input/G_$i > output/G_$i.out
    diff output/G_$i output/G_$i.out
done

