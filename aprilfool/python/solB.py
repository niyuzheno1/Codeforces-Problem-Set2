import sys
import argparse
import math

def main():
    n = int(input())
    m = math.sqrt(n)
    m = int(m)
    if m * m == n:
        print(m)
    else:
        print(-1)

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()