import sys
import argparse


def main():
    for _ in range(int(input())):
        n = int(input())
        a = list(map(int,input().split()))
        cnt = 0
        for i in range(n-1):
            mina = min(a[i],a[i+1])
            maxa = max(a[i],a[i+1])
            j = 0
            while j < 30:
                if maxa/ mina <= 2:
                    cnt = cnt + j
                    break
                j = j + 1
                mina *= 2
                
        print(cnt)
            

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()