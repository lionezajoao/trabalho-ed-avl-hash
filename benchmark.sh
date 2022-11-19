#!/bin/zsh

## MEDIAN TIME

get_median_time() {
    elem=$1
    hash_size=$2

    total=0

    for i in $(seq 1 5); do
        time=$(./bin/hash $elem $hash_size)
        seconds=$(($time/1000)) # milisegundos pra segundos
        total+=$seconds
    done

    echo "Média de tempo para $elem elementos e hash de tamanho $hash_size é $(($total/5))}"
}

## MAIN

SCRIPTPATH="$(cd "$(dirname "$0")" >/dev/null 2>&1 ; pwd -P)"
echo "SCRIPTPATH - $SCRIPTPATH"

clear
echo "COMPILING"
g++ $SCRIPTPATH/hash.cpp -o $SCRIPTPATH/bin/hash

echo "RUNNING"

get_median_time 1 10
get_median_time 100 1000
get_median_time 10000 100000
get_median_time 1000000 10000000
get_median_time 100000000 1000000000
get_median_time 1000000000 10000000000