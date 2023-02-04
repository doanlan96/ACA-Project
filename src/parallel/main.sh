#!/bin/bash
# build and run
clear
rm a.out
mpic++ -std=c++11 main.cpp
#mpiexec -n 16 --oversubscribe ./a.out /home/saurav_anand01/ACA-Project-main/data/GRCh38_Human/GRCh38  ../../data/patternHuman.txt
mpiexec -n $1  ./a.out /home/saurav_anand01/ACA-Project-main/data/GRCh38_Human/GRCh38  ../../data/patternHuman.txt
