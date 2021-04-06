import sys
import argparse
import math


def tmp():
    
    for i in range(2,100):
        c = i+1
        b = i
        x = int(math.sqrt(c**2 - b**2))
        if x*x == c**2 - b**2:
            print(x, i, (i+1))
def main():
    for _ in range(int(input())):
        n = int(input())
        x = int(math.sqrt(n/2))
        while 2*x*(x+1)+1 <= n:
            x = x+1
        print(x-1)


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()