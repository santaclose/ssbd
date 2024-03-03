#!/bin/bash
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'
if [ $# -eq 0 ]
then
	find src -type f | grep \\.c$ | while read line ; do ./compile.sh $line ; done
#	echo "Usage: compile C_FILE_PATH"
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
mkdir -p $(dirname "bin/${1%.*}")
echo COMPILING $1
./tools/ido-static-recomp/build7.1/out/cc -- mips-linux-gnu-as -32 -- -c -G 0 -non_shared -Xfullwarn -Xcpluscomm -Iinclude -Isrc -DF3DEX_GBI_2 -Wab,-r4300_mul -woff 649,838,712,568,624,709 -mips2 -O2 -o bin/${1%.*}.o $1
#./tools/ido-static-recomp/build7.1/out/cc -- mips-linux-gnu-as -32 -- -c -G 0 -non_shared -Xfullwarn -Xcpluscomm -Iinclude -Isrc -Wab,-r4300_mul -mips2 -O2 $1
#mv *.o ./bin/c
if [ $? -ne 0 ]; then
	echo -e "${RED}COMPILATION FAILED${NC}"
	exit
fi

echo -e "${GREEN}COMPILATION SUCCEEDED${NC}"
find bin/src/ -type f | grep \\.o$ | while read line ; do mips-linux-gnu-objcopy -O binary --only-section=.text ${line} ${line}.text ; done


#nameWithoutExtension=$(basename $1)
#nameWithoutExtension=${nameWithoutExtension%.*}
#mips-linux-gnu-ld -T symbols.ld ./bin/${nameWithoutExtension}.o -o ./bin/${nameWithoutExtension}.o.l
#if [ $? -ne 0 ]; then
#	echo SYMBOL RESOLVE FAILED
#	exit
#fi
#xxd ./bin/${nameWithoutExtension}.o.l > ./bin/${nameWithoutExtension}.o.l.h
#python ./tools/disasm.py -h ./bin/${nameWithoutExtension}.o.l.h > ./bin/${nameWithoutExtension}.o.l.hm
#python ./tools/matchbin.py ./bin/${nameWithoutExtension}.o.l baserom.z64
