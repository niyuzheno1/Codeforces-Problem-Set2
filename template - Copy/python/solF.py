import sys
import argparse
import collections

# 1 2 3 1 2 
# 1 1
# 2 3

def main():
    input = sys.stdin.readline
    n = int(input())
    a = list(map(int,input().split()))
    ans = 0
    S = set()
    la = -1
    for i in range(0,n):
        if a[i] == la:
            continue
        if a[i] in S:
            S = {a[i], la}
            continue
        S.add(a[i])
        la = a[i]
        ans = ans + 1 
    print(ans)
        
def main2():
    input = sys.stdin.readline
    n = int(input())
    a = list(map(int,input().split()))
    a = [-1] + a
    n = len(a)
    b = [0] + []
    for i in range(1,n):
        if a[i] != a[i-1]:
            b.append(a[i])
    mb = len(b)
    next = [0] * mb
    f = { x: mb for x in b}
    for i in range(mb-1, -1, -1):
        next[i] = f[b[i]]
        f[b[i]] = i
    subcnt = [0] * mb
    for i in range(1,mb):
        if b[i] != b[i-1]:
            subcnt[i] = 1
    for i in range(1,mb):
        subcnt[i] += subcnt[i-1]
    q = collections.deque([])
    q.append([0,0,0])
    ans = -1
    while q:
        x, y, c = q.popleft()
        if max(x,y) == mb or max(x,y) == mb-1:
            ans = (c if ans == -1 else min(ans, c))
            continue
        nx = next[x]
        ny = next[x]-1
        nc = c+ subcnt[ny] - subcnt[x+1] + (b[x+1] != b[y])
        q.append([nx, ny, nc])
        
        nx = x+1
        ny = y
        nc = c + (b[x+1] != b[x])
        q.append([nx, ny, nc])
        
    print(ans)
if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()