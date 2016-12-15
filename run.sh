#!/bin/bash

./comp testcase > test.c
dot -Tpdf tree.dot -otree.pdf
#evince tree.pdf > /dev/null
g++ -g test.c -o test.o
cat test.c
