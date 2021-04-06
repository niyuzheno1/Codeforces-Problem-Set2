import sys
import argparse


def main():
    n = int(input())
    for i in range(1,n):
        for j in range(1,n):
            if i & j == j and i + j <= n:
                print(i, i + j)

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()