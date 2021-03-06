import sys
import string
import matplotlib
import matplotlib.pyplot as plt
import numpy as np 
import math

def func(x):
    return np.sqrt(1 - (float(x) ** 2)) - (np.e ** float(x)) + 0.1

def lhs_func(x):
    return float(x) ** 2

def rhs_func(x):
    return (1.1 - np.e ** float(x)) * ( np.e ** float(x) + 0.9)

def fi(x):
    return np.log(np.sqrt(1 - x ** 2) + 0.1)

def fi_d(x):
    return (x * (1 - x ** 2)) / (np.sqrt(1 - x ** 2) + 0.1)

def IncorrectUsage():
        print("Incorrect usage")
        print("python3 draw_plot.py <method>")
        print("1 - Newton, 2 - simple iteration")
        exit(-1)
def main():
    if len(sys.argv) < 2:
        IncorrectUsage()
    method = int(sys.argv[1])

    if method == 1:
        i = -0.999
        x_value = list()
        y_value = list()
        while i < 0.999:
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

    elif method == 2:
        i = -2
        rhs_x_value = list()
        rhs_y_value = list()
        lhs_x_value = list()
        lhs_y_value = list()
        while i < 1:
            rhs_x_value.append(i)
            rhs_y_value.append(rhs_func(i))
            lhs_x_value.append(i)
            lhs_y_value.append(lhs_func(i))
            i += 0.0001

        x_1 = [-2, 2]
        x_2 = [0, 0]
        y_1 = [0, 0]
        y_2 = [-5, 5]
        plt.plot(y_1, y_2)
        plt.plot(x_1, x_2)
        plt.plot(rhs_x_value, rhs_y_value)
        plt.plot(lhs_x_value, lhs_y_value)
        plt.xlabel('x axis')
        plt.ylabel('y axis')
        plt.show()
    elif method == 3:
        x_value = list()
        y_value = list()
        i = 0
        while i < 0.15:
            x_value.append(i)
            y_value.append(fi(i))
            i += 0.0001
                    
        x_1 = [-2, 2]
        x_2 = [0, 0]
        y_1 = [0, 0]
        y_2 = [-5, 5]
        plt.plot(y_1, y_2)
        plt.plot(x_1, x_2)
        plt.plot(x_value, y_value)
        plt.xlabel('x axis')
        plt.ylabel('fi(x) axis')
        plt.show()
    elif method == 4:
        x_value = list()
        y_value = list()
        i = 0
        while i < 0.15:
            x_value.append(i)
            y_value.append(fi_d(i))
            i += 0.0001
                    
        x_1 = [-2, 2]
        x_2 = [0, 0]
        y_1 = [0, 0]
        y_2 = [-5, 5]
        plt.plot(y_1, y_2)
        plt.plot(x_1, x_2)
        plt.plot(x_value, y_value)
        plt.xlabel('x axis')
        plt.ylabel('fi_d(x) axis')
        plt.show()
if __name__ == "__main__":
    main()