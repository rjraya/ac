#!/bin/bash
lista=( 1 2 3 4 5 6 7 8 9 10 )
for i in "${lista[@]}"
do
  ./bench4 >> datos
  sleep 2
done

