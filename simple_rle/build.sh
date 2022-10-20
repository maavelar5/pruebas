#!/bin/bash


CFLAGS="\
-Wall \
-Werror \
"

gcc $CFLAGS main.c -o rledec -O0 -ggdb && ./rledec

