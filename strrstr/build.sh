#!/bin/bash


CFLAGS="\
-Wall \
-Werror \
"

gcc $CFLAGS main.c -o strrstr -O0 -ggdb && ./strrstr

