#!/bin/bash
rm -r asm
rm -r assets/
rm smashbrothers.ld
rm undefined_*
rm smashbrothers.d
#python -m splat split smashbrothers.yaml
python ./tools/splat/split.py smashbrothers.yaml
