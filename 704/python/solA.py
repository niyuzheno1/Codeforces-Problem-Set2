import sys
import argparse


def main():
    n = int(input())
    for i in range(n):
        a = list(map(int,input().split()))
        minval = (a[1]-(a[0]%a[1]))%a[1]
        for i in range(1,4):
            minval = min(minval,(a[i]-(a[0]%a[i]))%a[i])
        print(minval)

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()