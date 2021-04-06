import sys
import argparse


def main():
    for _ in range(int(input())):
        x = int(input())
        while (x & 1) == 0:
            x = x >> 1
        if x == 1:
            print("NO")
        else:
            print("YES")


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()