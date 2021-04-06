import sys
import argparse


def main():
    for _ in range(int(input())):
        n = int(input())
        a =  list(map(int,input().split()))
        b = [0] * n
        curmax = -1
        for i in range(n):
            if a[i] > curmax:
                b[i] = 1
            curmax = max(curmax,a[i])
        c = []
        for i in range(n-1,-1,-1):
            if b[i] == 1:
                c.append(a[i])
                for j in range(i+1, n):
                    if b[j] == 1:
                        break
                    c.append(a[j])
        print(" ".join(list(map(str,c))))


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()