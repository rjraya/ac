#!/bin/bash
#PBS -q ac
for i in `seq 2 12`;
do
export OMP_NUM_THREADS=$i
$PBS_O_WORKDIR/ej10 5000
$PBS_O_WORKDIR/ej10 10000
$PBS_O_WORKDIR/ej10 20000
done
