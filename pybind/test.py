#!/usr/bin/env python3

import sys
sys.path.append('../build/pybind')
import adder
# go into build file with adder (in this case) terminal. Then python3 in terminal. import sudoku (or adder in this case)    ./test.py

# n = 0
# for i in range(0, 100000000):
#     n = n + 1

n = adder.increment(0, 100000000) # difference is almost 5 seconds

print(n)