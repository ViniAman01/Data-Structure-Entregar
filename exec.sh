#!/bin/bash
gcc -c float_vector.c
gcc -c sort.c
gcc -c main.c
gcc float_vector.o sort.o main.o -o main
./main