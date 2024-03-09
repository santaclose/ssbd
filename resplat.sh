#!/bin/bash

rm -r assets
rm -r asm
#python -m splat split smashbrothers.yaml
python ./tools/splat/split.py smashbrothers.yaml
