import sys
import argparse


def main():
    n,q =list(map(int,input().split()))
    a = list(map(int,input().split()))
    for i in range(0,q):
        x = int(input())
        j = x-1
        while j < n:
            xx = a[j]
            a[j] = a[j]-1
            a[j] = max(a[j],1)
            j = j + xx
        print(a)

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()