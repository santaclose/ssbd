#!/bin/bash

find bin/c/ -type f | grep \\.o.text$ | while read line
do
	fileName=$(basename $line)
	asmPath=bin/asm/${fileName}
	if [ -f "$asmPath" ]
	then
		echo $asmPath
		python tools/matchbin.py ${line} ${asmPath}
	else
		echo "File not found: $asmPath"
	fi
done
