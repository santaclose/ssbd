#!/bin/bash

find assets -type f | while read line
do
	mkdir -p bin/$(dirname $line)
	mips-linux-gnu-objcopy -I binary -O elf32-tradbigmips -B mips $line bin/${line%.*}.o
done
