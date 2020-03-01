#!/bin/bash

rm -f $1
rm -f $1.o
gcc -o $1 $1.c
./$1
