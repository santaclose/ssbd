#!/usr/bin/python3
import os
import sys
import binascii

def match(subBinFilePath, binFilePath, subBinStartOffset = 0x0):
	INSTR_SIZE = 4
	curBinOffset = 0x0
	matchedInstructions = 0
	binFileSize = 0
	with open(subBinFilePath, 'rb') as subBinFile:
		subBinFile.seek(subBinStartOffset)
		with open(binFilePath, 'rb') as binFile:
			binFile.seek(0, 2)
			binFileSize = binFile.tell()
			binFile.seek(0)
			while (binChunk := binFile.read(INSTR_SIZE)):
				currentBlock = []
				currentBlockLocation = curBinOffset
				while (subBinChunk := subBinFile.read(INSTR_SIZE)):
					if binChunk != subBinChunk:
						subBinFile.seek(subBinStartOffset)
						if len(currentBlock) > 16:
							matchedInstructions = len(currentBlock)
							lineCount = len(currentBlock) // 4
							print(f"match at: {hex(currentBlockLocation)}")
							print(f"          {lineCount} lines ({hex(currentBlockLocation)} - {hex(currentBlockLocation + lineCount * 16)})")
							print(f"          {matchedInstructions} instructions")
						break
					currentBlock.append(subBinChunk)
					binChunk = binFile.read(INSTR_SIZE)
					curBinOffset += INSTR_SIZE
				curBinOffset += INSTR_SIZE
	print(f"matched {matchedInstructions} instructions out of {binFileSize//INSTR_SIZE} ({(matchedInstructions/(binFileSize//INSTR_SIZE)):.2f}%)")

subBinFilePath = sys.argv[1]
binFilePath = sys.argv[2]

match(subBinFilePath, binFilePath)
