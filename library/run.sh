#!/bin/bash

make
clang -Wall -Werror -Wextra -fsanitize=address -fsanitize=undefined -fsanitize=integer -DDEBUG=1 -g3 -fno-omit-frame-pointer -MMD -MP main.c libslib.a && ./a.out

