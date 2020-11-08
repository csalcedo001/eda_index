#!/bin/bash

for i in 1 2 4 8 16 32 64 128 256 512 1024 2048
do
	echo "$1 $i" | ./bin/input_generator | ./bin/disk_calls
done
