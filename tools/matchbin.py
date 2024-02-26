#!/usr/bin/python3
import os
import re
import sys
import binascii
import rabbitizer

patternInstr = r"^(\w+)\s+(.+)$"
patternReg = r"\$\w+"

def instructionsDiffer(bytesA, bytesB, ignoreOffsets = True):
	if ignoreOffsets:
		asmb = f"{rabbitizer.Instruction(int.from_bytes(bytesA, byteorder='big'))}"
		asmsb = f"{rabbitizer.Instruction(int.from_bytes(bytesB, byteorder='big'))}"
		mb = re.match(patternInstr, asmb)
		msb = re.match(patternInstr, asmsb)
		if mb is None or msb is None:
			chunksDiffer = asmb != asmsb
		elif mb.group(1) != msb.group(1):
			chunksDiffer = True
		else:
			regsb = re.findall(patternReg, mb.group(2))
			regssb = re.findall(patternReg, msb.group(2))
			chunksDiffer = len(regsb) != len(regssb) or any([regsb[i] != regssb[i] for i in range(len(regsb))])
	else:
		chunksDiffer = bytesA != bytesB
	return chunksDiffer


def match(subBinFilePath, binFilePath, subBinStartOffset = 0x0, ignoreOffsets = True):
	INSTR_SIZE = 4
	curBinOffset = 0x0
	matchedInstructions = 0
	differentRanges = []

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
			if binFileSize < subBinFileSize:
				binFile, subBinFile = subBinFile, binFile
				binFileSize, subBinFileSize = subBinFileSize, binFileSize

			while (binChunk := binFile.read(INSTR_SIZE)):
				while (subBinChunk := subBinFile.read(INSTR_SIZE)):
					if instructionsDiffer(binChunk, subBinChunk):
						if len(differentRanges) > 0 and differentRanges[-1][1] == hex(curBinOffset - INSTR_SIZE):
							differentRanges[-1] = (differentRanges[-1][0], hex(curBinOffset))
						else:
							differentRanges.append((hex(curBinOffset), hex(curBinOffset)))
					else:
						matchedInstructions += 1
					binChunk = binFile.read(INSTR_SIZE)
					curBinOffset += INSTR_SIZE
				curBinOffset += INSTR_SIZE

	print(f"   binary instruction count:     {binFileSize//INSTR_SIZE}")
	print(f"   sub-binary instruction count: {subBinFileSize//INSTR_SIZE}")
	print(f"   matched {matchedInstructions} instructions out of {binFileSize//INSTR_SIZE} ({(matchedInstructions/(binFileSize//INSTR_SIZE)):.2f}%)")
	print(f"   differences:")
	for d in differentRanges:
		if d[0] == d[1]:
			print(f"     {d[0]}")
		else:
			print(f"     {d[0]} - {d[1]}")

subBinFilePath = sys.argv[1]
binFilePath = sys.argv[2]

match(subBinFilePath, binFilePath)
