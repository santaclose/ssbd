#!/bin/bash
if [ $# -eq 0 ]
then
	echo "Usage: compile C_FILE_PATH"
	exit
fi
/usr/local/bin/ido_recomp/7.1/cc -v -- mips-linux-gnu-as -32 -- -c -G 0 -non_shared -Xfullwarn -Xcpluscomm -Iinclude -Isrc -Wab,-r4300_mul -woff 649,838,712 -mips2 -O2 $1 #2> /dev/null
if [ $? -ne 0 ]; then
	echo COMPILATION FAILED
	exit
fi
xxd ${1%.*}.o > ${1%.*}_hex.txt
hextomips ${1%.*}_hex.txt > ${1%.*}_hex_mips.txt
