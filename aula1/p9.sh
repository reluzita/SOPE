#!/bin/bash

cd ..
counter=3
while [ $counter -le 10 ]
do
    mkdir -p -v aula$counter
    ((counter++))
done