#!/bin/bash
RED="\e[31m"
GREEN="\e[32m"
ENDCOLOR="\e[0m"

#mips-linux-gnu-ld -o bin/builtRom.z64 -T undefined_funcs_auto.txt -T undefined_syms_auto.txt -T symbols/libultra.txt -T symbols/not_found.txt -T smashbrothers.ld
mips-linux-gnu-ld -o /tmp/smashbrothers.elf -T .splat/undefined_funcs_auto.txt -T .splat/undefined_syms_auto.txt -T symbols/not_found.txt -T .splat/smashbrothers.ld
#mips-linux-gnu-ld -T build/undefined_syms.txt -T build/ldscript.txt --no-check-sections --accept-unknown-input-arch --emit-relocs -Map build/mm.map -o mm.us.rev1.rom_uncompressed.elf
#mips-linux-gnu-ld -T undefined_syms_auto.txt -T symbols/not_found.txt -T smashbrothers.ld --no-check-sections -- accept-unknown-input-arch --emit-relocs -Map bin/smashbrothers.map -o built_rom_uncompressed.elf

mips-linux-gnu-objcopy --pad-to=0xC00000 --gap-fill=0xFF /tmp/smashbrothers.elf bin/builtRom.z64 -O binary

hashA=$(md5sum bin/builtRom.z64)
hashB=$(md5sum baserom.z64)
#echo $hashA
#echo $hashB
if [ "${hashA:0:32}" = "${hashB:0:32}" ]; then
    echo -e "${GREEN}BUILT ROM MATCHES${ENDCOLOR}"
else
    echo -e "${RED}BUILT ROM DOESN'T MATCH${ENDCOLOR}"
fi
