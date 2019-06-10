import random
import sys
def GenerateMatrix(m, n, out_file):
    output = open(out_file, "w+")
    output.write(str(m) + " " + str(n) + "\n")
    for _ in range(m):
        for _ in range(n):
            val = random.randrange(-1000, 1000)
            output.write(str(val) + " ")
        output.write("\n")
    output.close()

def main():
    if len(sys.argv) != 4:
        print("USAGE : matrix_generator.py <matrix size> <matrix size> <count of matrixes>")
        exit(-1)
    m = int(sys.argv[1])
    n = int(sys.argv[2])
    count = int(sys.argv[3])
    output = "./input/"
    for i in range(count):
        GenerateMatrix(m, n, output + str(i) + ".t")

if __name__ == "__main__":
    main()