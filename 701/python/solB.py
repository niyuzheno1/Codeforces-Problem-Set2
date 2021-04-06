import sys
import argparse


def main():
    input = sys.stdin.readline
    n,q,k = list(map(int,input().split()))
    a = list(map(int,input().split()))

    # preprocessing
    pre = [0]*n
    for i in range(n):
        if i >= 1:
            pre[i] = pre[i-1]
        if i == 0:
            pre[i] += a[i+1]-2
        elif i == n-1: 
            pre[i] += a[i-1]-2
        else:   
            pre[i] += a[i+1]-a[i-1]-2
    for i in range(q):
        l,r = list(map(int,input().split()))
        l,r = l-1, r-1
        ans = 0
        if l == r:
            ans = k-1
        else:
            ans += pre[r-1]-pre[l]
            # x = pre[r-1]-pre[l+1] if l+1 and r-1 is in a good range
            ans += a[l+1]-2
            ans += k-a[r-1]-1
        print(ans)


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()