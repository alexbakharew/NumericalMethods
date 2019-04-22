import sys
import string
import matplotlib
import matplotlib.pyplot as plt
import numpy as np 
import math

def func(x):
    return np.sqrt(1 - float(x) ** float(x)) - np.e ** float(x) + 0.01

x_value = list()
y_value = list()

i = 0
while i < 1:
    x_value.append(i)
    y_value.append(func(i))
    i += 0.0001
    
plt.plot(x_value, y_value)
plt.xlabel('x axis')
plt.ylabel('y axis')
plt.show()