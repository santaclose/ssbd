#!/usr/bin/python3
import os
import sys
import binascii

def match(subBinFilePath, binFilePath, subBinStartOffset = 0x0):
	INSTR_SIZE = 4
	curBinOffset = 0x0
	matchedInstructions = 0
	differences = []

	subBinFileSize = 0
	binFileSize = 0
	with open(subBinFilePath, 'rb') as subBinFile:
		subBinFile.seek(0, 2)
		subBinFileSize = subBinFile.tell()
		subBinFile.seek(subBinStartOffset)
		with open(binFilePath, 'rb') as binFile:
			binFile.seek(0, 2)
			binFileSize = binFile.tell()
			binFile.seek(0)

			while (binChunk := binFile.read(INSTR_SIZE)):
				while (subBinChunk := subBinFile.read(INSTR_SIZE)):
					if binChunk == subBinChunk:
						matchedInstructions += 1
					else:
						differences.append(curBinOffset)
					binChunk = binFile.read(INSTR_SIZE)
					curBinOffset += INSTR_SIZE
				curBinOffset += INSTR_SIZE

	print(f"   binary instruction count:     {binFileSize//INSTR_SIZE}")
	print(f"   sub-binary instruction count: {subBinFileSize//INSTR_SIZE}")
	print(f"   matched {matchedInstructions} instructions out of {binFileSize//INSTR_SIZE} ({(matchedInstructions/(binFileSize//INSTR_SIZE)):.2f}%)")
	print(f"   differences: {[hex(x) for x in differences]}")

subBinFilePath = sys.argv[1]
binFilePath = sys.argv[2]

match(subBinFilePath, binFilePath)
