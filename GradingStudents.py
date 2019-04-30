#!/bin/python3

import os


def findNext(item):
    while item % 5 != 0:
        item += 1
    return item


#
# Complete the gradingStudents function below.
#

def gradingStudents(grades):
    grades_ = []
    for item in grades:
        if item < 38:
            grades_.append(item)
        else:
            if item % 5 == 0:
                grades_.append(item)
            else:
                var = findNext(item)
                if abs(var - item) < 3:
                    grades_.append(var)
                else:
                    grades_.append(item)
    return grades_


if __name__ == '__main__':
    f = open(os.environ['OUTPUT_PATH'], 'w')

    n = int(input())

    grades = []

    for _ in range(n):
        grades_item = int(input())
        grades.append(grades_item)

    result = gradingStudents(grades)

    f.write('\n'.join(map(str, result)))
    f.write('\n')

    f.close()

