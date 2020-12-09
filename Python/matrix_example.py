
import numpy as np

print("Insert the two matrix dimensions: ", end="")
x = int(input())
y = int(input())

A = []
for i in range(x):
    # create empty row (a sublist inside our list)
    A.append([])
    for j in range(y):
        A[i].append(j)
print(A)


