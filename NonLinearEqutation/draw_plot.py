import sys
import string
import matplotlib
import matplotlib.pyplot as plt
import numpy as np 
import math

def func(x):
    return np.sqrt(1 - (float(x) ** 2)) - (np.e ** float(x)) + 0.01

x_value = list()
y_value = list()

i = -0.999
while i < 1:
    x_value.append(i)
    y_value.append(func(i))
    i += 0.0001

x_1 = [-2, 2]
x_2 = [0, 0]
y_1 = [0, 0]
y_2 = [-5, 5]
plt.plot(y_1, y_2)
plt.plot(x_1, x_2)

plt.plot(x_value, y_value)
plt.xlabel('x axis')
plt.ylabel('y axis')
plt.show()