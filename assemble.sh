#!/bin/bash

mkdir -p bin/asm
find asm/ -type f | grep \\.s$ | grep -v /data/ | while read line
do
#	~/test/binutils-2.42/gas/as-new -EB -I include -march=vr4300 -mabi=32 -o bin/${line%.*}.o $line
#	~/test/binutils-2.37/gas/as-new -EB -I include -march=vr4300 -mabi=32 -o bin/${line%.*}.o $line
	mips-linux-gnu-as -EB -I include -march=vr4300 -mabi=32 -o bin/${line%.*}.o $line
#	mips64-elf-as -EB -I include -march=vr4300 -mabi=32 -o bin/${line%.*}.o $line
done

find bin/asm/ -type f | grep \\.o$ | while read line ; do mips-linux-gnu-objcopy -O binary --only-section=.text ${line} ${line}.text ; done
