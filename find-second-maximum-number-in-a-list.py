if __name__ == '__main__':
    n = int(input())
    arr = [int(i) for i in input().strip().split()]
    arr.sort()
    # print(arr)
    max_ = arr[len(arr) - 1]
    for i in range(len(arr) - 1, -1, -1):
        # print(i)
        if arr[i] != max_:
            max_ = arr[i]
            break
    print(max_)

