#!/bin/bash

for dict in french spanish italian german portuguese
do
	echo "$dict"

	rm "data/index/$dict.dat"
	touch "data/index/$dict.dat"

	for i in 1 2 4 8 16 32 64 128 256 512 1024 2048
	do
		echo "$dict $i" | ./bin/input_generator | ./bin/disk_calls
	done
done
