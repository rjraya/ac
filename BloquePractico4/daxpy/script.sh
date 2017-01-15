#!/bin/bash
lista=( 100000000
for i in "${lista[@]}"
do
  ./bench4 >> datos
  sleep 2
done

