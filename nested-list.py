# Python code to sort the tuples using second element
# of sublist Inplace way to sort using sort()


def sort_(sub_li):
    # reverse = None (Sorts in Ascending order)
    # key is set to sort using second element of
    # sublist lambda has been used
    sub_li.sort(key=lambda x: x[1])
    return sub_li


if __name__ == '__main__':
    arr = list()
    for _ in range(int(input())):
        name = input()
        score = float(input())
        arr.append([name, score])
    # print(arr)
    arr = sort_(arr)
    min_ = arr[0][1]
    for i in range(len(arr)):
        if arr[i][1] > min_:
            min_ = arr[i][1]
            break
    # print(min_)
    result = list()
    for i in range(len(arr)):
        if arr[i][1] == min_:
            result.append(arr[i][0])
    result.sort()
    for i in result:
        print(i)
