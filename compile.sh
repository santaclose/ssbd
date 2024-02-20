#!/bin/bash
if [ $# -eq 0 ]
then
	echo "Usage: compile C_FILE_PATH"
	exit
fi

if [ ! -f ./tools/ido-static-recomp/build7.1/out/cc ]; then
	which python > /dev/null
	if [ $? -ne 0 ]; then
		echo Python required to build ido-static-recomp
		exit
	fi
	pushd ./tools/ido-static-recomp/ && python ./build.py ./ido/7.1/ && popd
fi
./tools/ido-static-recomp/build7.1/out/cc -- mips-linux-gnu-as -32 -- -c -G 0 -non_shared -Xfullwarn -Xcpluscomm -Iinclude -Isrc -Wab,-r4300_mul -woff 649,838,712 -mips2 -O2 $1 #2> /dev/null
if [ $? -ne 0 ]; then
	echo COMPILATION FAILED
	exit
fi
