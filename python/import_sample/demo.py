
"""
important sample method

求 y = x^2 在[-10, 10]上的积分

"""

import numpy as np
import matplotlib.pyplot as plt

N = 1000
res = 666.6666666667


def uniform_sample():
    x = np.random.uniform(-10, 10, N)
    y = x**2

    pi = 1 / 20

    inte = y.sum() / pi / N
    return np.abs(inte - res)


def important_sample():
    x_tmp = np.random.uniform(0, 1, N)
    p1 = np.ones_like(x_tmp)
    p1[x_tmp < 0.5] = -1
    x = np.sqrt(200 * np.abs(x_tmp - 0.5)) * p1

    y = x**2
    p = np.abs(x / 100)
    inte = np.sum(y / p) / N
    return np.abs(inte - res)


n = 1000
r1 = []
r2 = []
for i in range(n):
    r1.append(uniform_sample())
    r2.append(important_sample())

print(np.sum(r1) / n)
print(np.sum(r2) / n)
