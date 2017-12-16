T = int(input())

def isPresent(first, data, arr):
    for i in range(first, len(arr)):
        if arr[i] == data:
            return True
    return False

while T:
    N = int(input())
    a = list(map(int, input().strip().split(' ')))
    if len(a) != N:
        break
    a = set(a)

    a = list(a)
    result = []
    for i in range(len(a)-1):
        if isPresent(i, -a[i], a):
            result.append(-a[i])
            result.append(a[i])
    for j in range(len(result)):
        print(str(result[j]) + " ", end="")
