import numpy as np
import torch
import torch.nn as nn
import torch.optim as optim
from torch.autograd import Variable
from torch.utils.data import DataLoader
from torch.utils.data import sampler

import torchvision.datasets as dset
import torchvision.transforms as T

import numpy as np

import timeit
def f(A,C):
    n = A.shape[0]
    Z = A.dot(C)
    # print("A:")
    # print(A)
    # print("Z:")
    # print(Z)
    B = np.zeros_like(A)
    for i in range(n):
        for j in range(n):
            if i != j and (A[i][j] == 1 or Z[i][j] > 0):
                B[i][j] = 1
    # print("B:")
    # print(B)
    mask = 1 - np.eye(n)
    if (B == mask).all():
        # print("get")
        return 2*B - A
    T = f(B,C)
    X = T.dot(A)
    D = 2*T - 1
    for i in range(n):
        for j in range(n):
            if X[i][j] >= T[i][j] * np.sum(C, axis=1)[j]:
                D[i][j] += 1
    # print("return D:", D)
    return D

a = np.random.rand(5,5)
a[a < 0.5] = 0
a[a >= 0.5] = 1
# a = np.array([[1,0,1],[0,1,0],[0,0,1]])
print(a)
print(f(a,a))
