#!/bin/bash
for i in 1 2 4
do
  export OMP_NUM_THREADS=4
  ./schedule-clause 16 $i
done
