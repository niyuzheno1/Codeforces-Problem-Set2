import sys
import argparse


def main():
    for _ in range(int(input())):
        n = int(input())
        a = list(map(int, input().split()))
        u = min(a)
        cnt = sum([1 if x == u else 0 for x in a])
        print(n-cnt)

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()