import numpy

N = int(input())
mat1 = list()
mat2 = list()
for i in range(N):
    a_ = [int(i) for i in input().strip().split()]
    mat1.append(a_)
for i in range(N):
    a_ = [int(i) for i in input().strip().split()]
    mat2.append(a_)

mat1 = numpy.reshape(mat1, (N, N))
mat2 = numpy.reshape(mat2, (N, N))

print(mat1.dot(mat2))
