#!/bin/python3

import os
import sys


# Complete the migratoryBirds function below.
def migratoryBirds(arr):
    tmp = [0]*5
    for i in arr:
        tmp[i - 1] += 1

    index = 0
    max = -sys.maxsize

    for j in range(len(tmp)):
        if tmp[j] > max:
            max = tmp[j]
            index = j
    return index + 1


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    arr_count = int(input().strip())

    arr = list(map(int, input().rstrip().split()))

    result = migratoryBirds(arr)

    fptr.write(str(result) + '\n')

    fptr.close()

