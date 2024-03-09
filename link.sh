#!/bin/bash

#mips-linux-gnu-ld -o bin/builtRom.z64 -T undefined_funcs_auto.txt -T undefined_syms_auto.txt -T symbols/libultra.txt -T symbols/not_found.txt -T smashbrothers.ld
mips-linux-gnu-ld -o bin/builtRom.z64 -T undefined_funcs_auto.txt -T undefined_syms_auto.txt -T symbols/not_found.txt -T smashbrothers.ld
