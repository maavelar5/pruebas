#!/bin/bash


CFLAGS="\
-Wall \
-Wno-unused-variable \
-Werror \
"

gcc $CFLAGS main.c -o tgaloader -O0 -ggdb && ./tgaloader colornoise.tga

