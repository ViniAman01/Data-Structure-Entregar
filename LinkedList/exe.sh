#!/bin/bash
gcc -c linked_list.c
gcc -c main.c
gcc main.o linked_list.o -o main
./main
rm main main.o linked_list.o
