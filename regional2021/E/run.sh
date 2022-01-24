#!/bin/bash
g++ E.cpp -o E
for (( i=1; i <= 58 ; i++ ))
do
    ./E < input/E_$i > output/E_$i.out
    diff output/E_$i output/E_$i.out
done
