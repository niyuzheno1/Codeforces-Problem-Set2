import sys
import argparse


def main():
    for _ in range(int(input())):
        n, k = list(map(int,input().split()))
        h = list(map(int,input().split()))
        rem = -1
        while k > 0:
            k = k - 1
            good = False
            rem = -1
            for i in range(0, n-1):
                if h[i] < h[i+1]:
                    h[i] = h[i] + 1 
                    rem = i + 1
                    good = True
                    break
            if not good:
                break
        print(rem)

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()