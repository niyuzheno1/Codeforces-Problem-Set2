import sys
import argparse


def main():
    for _ in range(int(input())):
        n,k = list(map(int,input().split()))
        a = list(map(int,input().split()))
        for i in range(n):
            u = []
            for j in range(0,k):
                if(i + j) >= n:
                    break
                u.append(a[i+j])
            if(len(u) < k):
                break
            u = sorted(u)
            print("{} {} : {}".format(i+1, i+k , u[(k+1)//2-1]))

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()