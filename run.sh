#!/bin/bash

./comp testcase 
dot -Tpdf tree.dot -otree.pdf
#evince tree.pdf > /dev/null
g++ -g target.cc -o target
cat target.cc
