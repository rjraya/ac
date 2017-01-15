#!/bin/bash
#un bonito script
export OMP_NUM_THREADS=12
numeros=( 2 64 128 1024 )
planif=( "static" "dynamic" "guided")
for i in "${numeros[@]}"
do
  for j in "${planif[@]}" 
  do
  echo $i
  export OMP_SCHEDULE="$j,$i"
  ./ej7 15000
done
done