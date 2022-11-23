#!/bin/zsh

## EXEC

exec_script() {
    elem=$1
    hash_size=$2

    avg=$(./bin/$script_name $elem)

    echo $avg
}

## MAIN

script_path="$(cd "$(dirname "$0")" >/dev/null 2>&1 ; pwd -P)"
script_name="hash"

echo "COMPILING"
g++ $script_path/hash.cpp -o $script_path/bin/$script_name

echo "RUNNING"

init_elem_size=1000

# Quantidade de elementos de 1000 até 100.000.000
for i in $(seq 1 5);
do
    exec_script $init_elem_size
    let "init_elem_size=init_elem_size*10"

done


