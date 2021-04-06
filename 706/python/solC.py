import sys
import argparse
from math import sqrt

def main():
    input = sys.stdin.readline
    for _ in range(int(input())):
        n = int(input())
        a = []
        b = []
        for i in range(2*n):
            x = list(map(int,input().split()))
            if x[0] == 0:
                a.append(abs(x[1]))
            if x[1] == 0:
                b.append(abs(x[0]))
        a.sort()
        b.sort()
        ans = 0
        for i in range(n):
            ans += sqrt(a[i]*a[i] + b[i]*b[i])
        print(ans)

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()