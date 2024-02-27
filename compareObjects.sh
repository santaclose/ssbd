#!/bin/bash

find bin/c/ -type f | grep \\.o.text$ | while read line
do
	fileName=$(basename $line)
	asmPath=bin/asm/${fileName}
	nameWithoutExtension=${fileName%.*}
	nameWithoutExtension=${nameWithoutExtension%.*}
	binPath=targetBin/${nameWithoutExtension}.bin
	if [ -f "$asmPath" ]
	then
		echo $asmPath
		python tools/matchbin.py ${line} ${asmPath}
#		python tools/matchbin.py ${line} ${binPath}
	else
		echo "File not found: $asmPath"
	fi
done
