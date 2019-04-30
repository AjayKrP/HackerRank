import numpy
arr = list()
N, M = [int(i) for i in input().strip().split()]

for i in range(N):
    a_ = [int(i) for i in input().strip().split()]
    arr.append(a_)
arr = numpy.array(arr)
arr = numpy.reshape(arr, (N, M))

print(numpy.transpose(arr))
print(arr.flatten())
