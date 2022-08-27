#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'isBalanced' function below.
#
# The function is expected to return a STRING.
# The function accepts STRING s as parameter.
#

def isBalanced(s):
    stack = list()
    pair = {'{':'}','[':']','(':')'}
    for c in s:
        if not stack:
            stack.append(c)
        elif c == pair.get(stack[-1]):
            stack.pop()
        else:
            stack.append(c)
    return "YES" if not stack else "NO"
    # Write your code here

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input().strip())

    for t_itr in range(t):
        s = input()

        result = isBalanced(s)

        fptr.write(result + '\n')

    fptr.close()
