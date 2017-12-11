#!/bin/python3

import sys

g = int(input().strip())
for a0 in range(g):
    n, m, x = input().strip().split(' ')
    n, m, x = [int(n), int(m), int(x)]
    a = list(map(int, input().strip().split(' ')))
    b = list(map(int, input().strip().split(' ')))
    # your code goes here
    a = a[::-1]
    a.pop(len(a)-1)
    b = b[::-1]
    b.pop(len(b)-1)
    #a.reverse()
    #print(a)
    sum = 0
    itr = 0
    while sum <= x:
        if a[len(a) - 1] <= b[len(b) - 1]:
            sum += a[len(a) - 1]
            itr += 1
            a.pop()
        else:
            sum += a[len(a) - 1]
            itr += 1
            b.pop()
    print(itr)

