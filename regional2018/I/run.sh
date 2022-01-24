#!/bin/bash
g++ I.cpp -o I
for (( i=1; i <= 21; i++ ))
do
    ./I < input/I_$i > output/I_$i.out
    diff output/I_$i output/I_$i.out
done
