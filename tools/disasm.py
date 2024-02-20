#!/usr/bin/python3
import sys
import rabbitizer

def mipsInstrFromWordString(word):
	rabinstr = rabbitizer.Instruction(eval(f"0x{word.replace(' ', '')}"))
	rabinstrstr = f"{rabinstr}"
	return rabinstrstr[:rabinstrstr.find(' ') if ' ' in rabinstrstr else len(rabinstrstr)]

def addInstrToHexDump(inFilePath):
	with open(inFilePath, 'r') as inFile:
		for line in inFile.readlines():
			a = mipsInstrFromWordString(line[10:19])
			b = mipsInstrFromWordString(line[20:29])
			c = mipsInstrFromWordString(line[30:39])
			d = mipsInstrFromWordString(line[40:49])
			print(line[:-1] + f'  {a}{" "*(8-len(a))}{b}{" "*(8-len(b))}{c}{" "*(8-len(c))}{d}')

def disassemble(inFilePath, littleEndian=False):
	with open(inFilePath, "rb") as f:
		while (word := f.read(4)):
			if littleEndian:
				print(rabbitizer.Instruction(int.from_bytes(word, byteorder='little')))
			else:
				print(rabbitizer.Instruction(int.from_bytes(word, byteorder='big')))

if __name__ == "__main__":
	if len(sys.argv) < 3:
		print("Usage: disasm -h disasm HEX_DUMP_FILE.txt")
		print("       disasm -b disasm BINARY_FILE [--little-endian]")
		sys.exit(1)
	if "-h" in sys.argv:
		addInstrToHexDump(sys.argv[2])
	else:
		disassemble(sys.argv[2], "--little-endian" in sys.argv)
