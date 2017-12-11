

def check_for_persent(arr, data):
    if data in arr:
        return True

def fibonacci(arr, x, y):
    arr.append(x)
    arr.append(y)
    #while arr[len(arr)-1] <= 1000:
    for i in arr:
        for j in arr:
            #print("length = " + str(len(arr)), i , j)
            if arr[len(arr)-1] <= 50 and i != j:
                temp = i + j
                if not check_for_persent(arr, temp):
                    arr.append(temp)
            if arr[len(arr)-1] > 50:
                arr.pop(len(arr)-1)
            #arr.sort()

if __name__== "__main__":
    x = 2
    y = 5
    arr = []
    fibonacci(arr, x, y)
    print(arr)



