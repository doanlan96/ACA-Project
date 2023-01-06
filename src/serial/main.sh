#!/bin/bash
# build and run
clear
# rm a.out
g++ -std=c++11 main.cpp
./a.exe ../../data/EscherichiaColi/genome.fna  ../../data/pat.txt
# rm a.out