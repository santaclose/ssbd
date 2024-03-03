#!/usr/bin/python3
import os
import re
import sys
import binascii
import rabbitizer
import disasm

patternInstr = r"^(\w+)\s+(.+)$"
patternReg = r"\$\w+"

def instructionsDiffer(bytesA, bytesB, onlyInstrAndRegisters = True):
	if onlyInstrAndRegisters:
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

def searchCode(binWithSequenceFilePath, sequenceOffset, binToLookFilePath):
	INSTR_SIZE = 4
	LINE_SIZE = 4 * INSTR_SIZE

	with open(binWithSequenceFilePath, 'rb') as binWithSequenceFile:
		with open(binToLookFilePath, 'rb') as binToLookFile:
			binWithSequenceFile.seek(sequenceOffset)
			threeLineSequence = ""
			for i in range(4 * 3):
				binWithSequenceChunk = binWithSequenceFile.read(INSTR_SIZE)
				threeLineSequence += disasm.mipsToString(int.from_bytes(binWithSequenceChunk, byteorder='big'), disasm.MIPS_TO_STRING_MODE_INSTR_AND_REGISTERS)
				threeLineSequence += '\n'
			twoLineSequence = ""
			for i in range(4 * 2):
				binWithSequenceChunk = binWithSequenceFile.read(INSTR_SIZE)
				twoLineSequence += disasm.mipsToString(int.from_bytes(binWithSequenceChunk, byteorder='big'), disasm.MIPS_TO_STRING_MODE_INSTR_AND_REGISTERS)
				twoLineSequence += '\n'
			oneLineSequence = ""
			for i in range(4 * 1):
				binWithSequenceChunk = binWithSequenceFile.read(INSTR_SIZE)
				oneLineSequence += disasm.mipsToString(int.from_bytes(binWithSequenceChunk, byteorder='big'), disasm.MIPS_TO_STRING_MODE_INSTR_AND_REGISTERS)
				oneLineSequence += '\n'

			binToLookDisassembled = ""
			while (binChunk := binToLookFile.read(INSTR_SIZE)):
				binToLookDisassembled += disasm.mipsToString(int.from_bytes(binChunk, byteorder='big'), disasm.MIPS_TO_STRING_MODE_INSTR_AND_REGISTERS)
				binToLookDisassembled += '\n'

			instrIndex = binToLookDisassembled.find(threeLineSequence)
			if instrIndex > -1:
				bytesToFoundMatch = binToLookDisassembled.count('\n', 0, instrIndex) * 4
				print(f"   Matched three lines at: {hex(bytesToFoundMatch)}")
				return
			instrIndex = binToLookDisassembled.find(twoLineSequence)
			if instrIndex > -1:
				bytesToFoundMatch = binToLookDisassembled.count('\n', 0, instrIndex) * 4
				print(f"     Matched two lines at: {hex(bytesToFoundMatch)}")
				return
			instrIndex = binToLookDisassembled.find(oneLineSequence)
			if instrIndex > -1:
				bytesToFoundMatch = binToLookDisassembled.count('\n', 0, instrIndex) * 4
				print(f"      Matched one line at: {hex(bytesToFoundMatch)}")
				return
			print(f"   Not found")



			# sequenceFirstLine = binWithSequenceFile.read(LINE_SIZE)
			# binWithSequenceFile.seek(sequenceOffset)
			# sequenceFirstTwoLines = binWithSequenceFile.read(LINE_SIZE * 2)
			# binWithSequenceFile.seek(sequenceOffset)
			# sequenceFirstThreeLines = binWithSequenceFile.read(LINE_SIZE * 3)

			# binToLook = binToLookFile.read()
			# lineIndex = binToLook.find(sequenceFirstThreeLines)
			# if lineIndex > -1:
			# 	print(f"   Matched three lines at: {hex(lineIndex)}")
			# 	return
			# lineIndex = binToLook.find(sequenceFirstTwoLines)
			# if lineIndex > -1:
			# 	print(f"   Matched two lines at: {hex(lineIndex)}")
			# 	return
			# lineIndex = binToLook.find(sequenceFirstLine)
			# if lineIndex > -1:
			# 	print(f"   Matched one line  at: {hex(lineIndex)}")
			# 	return
			# print(f"   Not found")
			# return




def match(subBinFilePath, binFilePath, subBinStartOffset = 0x0, onlyInstrAndRegisters = True):
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
					if instructionsDiffer(binChunk, subBinChunk, onlyInstrAndRegisters):
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
	print(f"   matched {matchedInstructions} instructions out of {binFileSize//INSTR_SIZE} ({(100.0*matchedInstructions/(binFileSize//INSTR_SIZE)):.2f}%)")
	if len(differentRanges) > 0:
		print(f"   differences:")
		for d in differentRanges:
			if d[0] == d[1]:
				print(f"     {d[0]}")
			else:
				print(f"     {d[0]} - {d[1]}")


if __name__ == "__main__":

	if sys.argv[1] == '-s':
		searchCode(sys.argv[2], eval(sys.argv[3]), sys.argv[4])
		sys.exit()

	subBinFilePath = sys.argv[1]
	binFilePath = sys.argv[2]

	match(subBinFilePath, binFilePath)
