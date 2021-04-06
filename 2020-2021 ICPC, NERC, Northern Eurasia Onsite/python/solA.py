# your code goes here
import math
import sys
import argparse


def main():
    input = sys.stdin.readline
    n, d = list(map(int,input().split()))
    a = list(map(float,input().split()))
    b = []
    for i in range(0,n):
        b.append(int(a[i]))
        a[i] = math.log(a[i])
    mlog = sum(a)
    f = [[0.0 for j in range(0,11)] for i in range(0,n)]
    c = [[[0,0] for j in range(0,11)] for i in range(0,n)]
    ans = []
    for i in range(n):
        if (i != 0) :
            for j in range(10):
                f[i][j] = f[i-1][j]
                c[i][j][0] = c[i-1][j][0]
                c[i][j][1] = c[i-1][j][1]
            for j in range(10):
                if f[i-1][j]+a[i] > f[i][(j*b[i])%10]:
                    f[i][(j*b[i])%10] = f[i-1][j]+a[i]
                    c[i][(j*b[i])%10][0] = i
                    c[i][(j*b[i])%10][1] = j
            if f[i][b[i]%10] < a[i]:
                f[i][b[i]%10] = a[i]
                c[i][b[i]%10][0] = i
                c[i][b[i]%10][1] = -1
            continue
        if (i == 0) :
            for j in range(10):
                f[i][j] = math.log(0.0001)-mlog
                c[i][j][0] = -1
                c[i][j][1] = -1
            f[i][b[0]%10] = a[0]
            c[i][b[0]%10][0] = 0
            c[i][b[0]%10][1]  = -1

            continue
    if(f[n-1][d] <= 0):
        print(-1)
        return 0
    x,y = c[n-1][d][0],c[n-1][d][1]
    while y != -1:
        ans.append(b[x])
        u = x-1
        if u < 0:
            break
        x = c[u][y][0]
        y = c[u][y][1]
    if x >= 0:
        ans.append(b[x])
    print(len(ans))
    print(" ".join(list(map(str,ans))))
    

if __name__ == "__main__":
    main()