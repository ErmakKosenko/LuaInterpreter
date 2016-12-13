#!/bin/bash

./comp testcase
dot -Tpdf tree.dot -otree.pdf
