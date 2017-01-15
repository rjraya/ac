#!/bin/bash
#script para los casos por defecto en atcgrid
export OMP_NUM_THREADS=12
planif=( "static" "dynamic" "guided")
for j in "${planif[@]}" 
do
  export OMP_SCHEDULE="$j"
  ./ej7 15000
done
