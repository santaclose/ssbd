#!/bin/bash

RED="\e[31m"
GREEN="\e[32m"
ENDCOLOR="\e[0m"

compile() {
	if [ ! -f ./tools/ido-static-recomp/build7.1/out/cc ]; then
		which python > /dev/null
		if [ $? -ne 0 ]; then
			echo Python required to build ido-static-recomp
			exit
		fi
		pushd ./tools/ido-static-recomp/ && python ./build.py ./ido/7.1/ && popd
	fi
	find src/ -type f | grep \\.c$ | while read line
	do
		mkdir -p $(dirname "bin/${line%.*}")
		./tools/ido-static-recomp/build7.1/out/cc -- mips-linux-gnu-as -32 -- -c -G 0 -non_shared -Xfullwarn -Xcpluscomm -Iinclude -Isrc -DF3DEX_GBI_2 -Wab,-r4300_mul -woff 649,838,712,568,624,709 -mips2 -O2 -o bin/${line%.*}.o $line
		if [ $? != 0 ] ; then echo -e "${RED}FAILED TO COMPILE FILE: $line ${ENDCOLOR}" && exit ; fi
	done
}

assemble() {
	find asm/ -type f | grep \\.s$ | while read line
	do
		mkdir -p $(dirname "bin/${line%.*}")
		mips-linux-gnu-as -EB -I include -march=vr4300 -mabi=32 -o bin/${line%.*}.o $line
		if [ $? != 0 ] ; then echo -e "${RED}FAILED TO ASSEMBLE FILE: $line ${ENDCOLOR}" && exit ; fi
	done
}

binToObjects() {
	find assets -type f | while read line
	do
		mkdir -p bin/$(dirname $line)
		mips-linux-gnu-objcopy -I binary -O elf32-tradbigmips -B mips $line bin/${line%.*}.o
		if [ $? != 0 ] ; then echo -e "${RED}FAILED TO CREATE OBJECT FROM BINARY: $line ${ENDCOLOR}" && exit ; fi
	done
}

assemble && binToObjects && compile

# Linking
mips-linux-gnu-ld -o /tmp/smashbrothers.elf -T .splat/undefined_funcs_auto.txt -T .splat/undefined_syms_auto.txt -T symbols/not_found.txt -T .splat/smashbrothers.ld

# Final binary
mips-linux-gnu-objcopy --pad-to=0xC00000 --gap-fill=0xFF /tmp/smashbrothers.elf bin/builtRom.z64 -O binary

# Compare hashes
hashA=$(md5sum bin/builtRom.z64)
hashB=$(md5sum baserom.z64)

if [ "${hashA:0:32}" = "${hashB:0:32}" ]; then
    echo -e "${GREEN}BUILT ROM MATCHES${ENDCOLOR}"
else
    echo -e "${RED}BUILT ROM DOESN'T MATCH${ENDCOLOR}"
fi
