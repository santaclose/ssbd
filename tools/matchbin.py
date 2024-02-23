#!/usr/bin/python3
import os
import sys
import binascii

def exactMatch(subBinFilePath, binFilePath):
	INSTR_SIZE = 4
	subBinStartOffset = 0x10000
	curBinOffset = 0x0
	foundMatch = False
	with open(subBinFilePath, 'rb') as subBinFile:
		subBinFile.seek(subBinStartOffset)
		with open(binFilePath, 'rb') as binFile:
			while (binChunk := binFile.read(INSTR_SIZE)):
				currentBlock = []
				currentBlockLocation = curBinOffset
				while (subBinChunk := subBinFile.read(INSTR_SIZE)):
					if binChunk != subBinChunk:
						subBinFile.seek(subBinStartOffset)
						if len(currentBlock) > 16:
							foundMatch = True
							lineCount = len(currentBlock) // 4
							print(f"match at: {hex(currentBlockLocation)}")
							print(f"          {lineCount} lines ({hex(currentBlockLocation)} - {hex(currentBlockLocation + lineCount * 16)})")
							print(f"          {len(currentBlock)} instructions")
						break
					currentBlock.append(subBinChunk)
					binChunk = binFile.read(INSTR_SIZE)
					curBinOffset += INSTR_SIZE
				curBinOffset += INSTR_SIZE
	if not foundMatch:
		print("couldn't match binaries")


subBinFilePath = sys.argv[1]
binFilePath = sys.argv[2]

exactMatch(subBinFilePath, binFilePath)
