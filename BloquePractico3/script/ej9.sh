#!/bin/bash
numeros=( 100 500 1000)
lista=( 1 2 3 4 5 6 7 8 9 10 11 12 )
for i in "${numeros[@]}"
do
  for j in "${lista[@]}"
  do
  	echo "numero de threads $j"
  	export OMP_NUM_THREADS="$j"
    ./l7/ej9 $i
  done
done

