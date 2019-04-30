#!/bin/python3

import math
import os
import random
import re
import sys


# Complete the breakingRecords function below.
def breakingRecords(scores):
    max = -sys.maxsize
    min = sys.maxsize
    cnt1 = -1
    cnt2 = -1
    for item in scores:
        if item > max:
            max = item
            cnt1 += 1
        if item < min:
            min = item
            cnt2 += 1
    #print(cnt1, cnt2)
    return [cnt1, cnt2]


"""
10
3 4 21 36 10 28 35 5 24 42
"""
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    scores = list(map(int, input().rstrip().split()))

    result = breakingRecords(scores)

    fptr.write(' '.join(map(str, result)))
    fptr.write('\n')

    fptr.close()

