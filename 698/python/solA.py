import sys
import argparse


def main():
    for _ in range(int(input())):
        n = int(input())
        a = {}
        b = list(map(int,input().split()))
        for i in range(n):
            a[b[i]] = 0 
        maxp = 0
        for i in range(n):
            a[b[i]] = a[b[i]]+1 
            maxp = max(maxp, a[b[i]])
        print(maxp)


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()