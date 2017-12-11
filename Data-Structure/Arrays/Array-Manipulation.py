#!/bin/python3

import sys

if __name__ == "__main__":
    # n, m = input().strip().split(' ')
    # n, m = [int(n), int(m)]
    # arr = [0]*n # For initialization
    # 
    # for a0 in range(m):
    #     a, b, k = input().strip().split(' ')
    #     a, b, k = [int(a), int(b), int(k)]
    #     print(a, b, k)
    #     for i in range(a-1, b):
    #         arr[i] = int(arr[i])+int(k)
    # 
    # print(max(arr))
    n, inputs = [int(n) for n in input().split(" ")]
    list = [0] * (n + 1)
    for _ in range(inputs):
        x, y, incr = [int(n) for n in input().split(" ")]
        list[x - 1] += incr
        if ((y) <= len(list)): list[y] -= incr;
    max = x = 0
    for i in list:
        x = x + i;
        if (max < x): max = x;
    print(max)
