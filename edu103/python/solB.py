import sys
import argparse


def main():
    for _ in range(int(input())):
        n, k = list(map(int,input().split()))
        p = list(map(int,input().split()))
        inc = 0
        csum = 0
        for i in range(n):
            if i == 0:
                csum += p[i]
                continue
            if p[i] * 100 - k * csum > 0:
                change = (p[i] * 100 - k * csum + k-1) // k
                inc += change
                csum += change 
            csum += p[i]
        print(inc)


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()