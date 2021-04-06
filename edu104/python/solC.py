import sys
import argparse


def main():
    for _ in range(int(input())):
        n = int(input())
        if n == 2:
            print(0)
            continue
        res = []
        for i in range(0,n):
            for j in range(i+1,n):
                if (i+1) % n == j:
                  res.append(1)
                elif i == 0 and j == n-1:
                  res.append(-1) 
                else:
                  res.append(0)
        print(" ".join(list(map(str,res))))

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()