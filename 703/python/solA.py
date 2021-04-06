import sys
import argparse


def main():
    for _ in range(int(input())):
        n = int(input())
        a = list(map(int,input().split()))
        b = [0] * n
        for i in range(n):
            b[i] = i
        flag = True
        for i in range(n-1):
            add = a[i]-b[i]
            if add < 0:
                flag == False
                break
            a[i] = b[i]
            a[i+1] += add
        for i in range(n-1):
            if a[i] >= a[i+1]:
                flag = False
                break
        print("YES" if flag == True else "NO")

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()