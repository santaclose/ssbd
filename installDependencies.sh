#!/bin/bash
RED="\e[31m"
GREEN="\e[32m"
ENDCOLOR="\e[0m"

if [ ! -f ./tools/ido-static-recomp/build7.1/out/cc ]
then
	which python > /dev/null
	if [ $? -ne 0 ]
	then
		echo -e ${RED}Python required to build ido-static-recomp${ENDCOLOR}
		exit
	fi
	pushd ./tools/ido-static-recomp/ && python ./build.py ./ido/7.1/ && popd
fi

which mips-linux-gnu-ld 2>&1 > /dev/null
if [ $? != 0 ]
then
	sudo apt install binutils-mips-linux-gnu
fi

if [ ! -f ./baserom.z64 ]
then
	echo -e ${RED}Rom not found, place it at $(pwd)/baserom.z64${ENDCOLOR}
	exit
fi

echo -e ${GREEN}All requirements satisfied${ENDCOLOR}