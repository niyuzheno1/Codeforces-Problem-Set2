import sys
import argparse


def main():
    f = [0]*1000010
    nn = len(f)
    f[0] = 1
    for i in range(0, nn):
        if i-2020 >= 0:
            f[i] = f[i] | f[i-2020]
        if i-2021 >= 0:
            f[i] = f[i] | f[i-2021]
    for _ in range(int(input())):
        x = int(input())
        if f[x] == 1:
            print("YES")
        else:
            print("NO")


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()