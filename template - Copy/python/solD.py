import sys
import argparse


def main():
    input = sys.stdin.readline
    n = int(input())
    a = list(map(int,input().split()))
    a.append(-1)
    next = [0]*(n+1)
    b = [n]
    c = [n]
    f = {}
    for i in range(n):
        f[a[i]] = n
    for i in range(n-1, -1, -1):
        next[i] = f[a[i]]
        f[a[i]] = i
    next[n] = n
    for i in range(n):
        mb = len(b)
        mc = len(c)
        if a[b[mb-1]] == a[i]:
            c.append(i)
            continue
        if a[c[mc-1]] == a[i]:
            b.append(i)
            continue
        if next[b[mb-1]] > next[c[mc-1]]:
            c.append(i)
            continue 
        b.append(i)
    mb = len(b)
    mc = len(c)
    cnt = 0
    for i in range(1,mb):           
        if a[b[i]] != a[b[i-1]]:
            cnt = cnt + 1
    for i in range(1,mc):           
        if a[c[i]] != a[c[i-1]]:
            cnt = cnt + 1
    print(cnt)

    
if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()