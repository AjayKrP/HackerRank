#!/bin/python3

import sys

def find_and_count(S, Query):
    ans = []
    for val in Query:
        cnt = 0
        for sol in S:
            if sol == val:
                cnt += 1
        ans.append(cnt)
    for val in ans:
        print(val)


if __name__ == "__main__":
    n = int(input())
    S = []
    for i in range(n):
        S.append(str(input()))
    Q = int(input())
    Query = []
    for i in range(Q):
        Query.append(str(input()))
    find_and_count(S, Query)



