import sys

def op1(n, x):
    for i in range(0,n):
        u = 2*i
        v = 2*i+1
        t1 = x[u]
        x[u] = x[v]
        x[v] = t1
    return x

def op2(n,x):
    for i in range(0,n):
        u = i
        v = i+n
        t1 = x[u]
        x[u] = x[v]
        x[v] = t1
    return x

def cmp(n,a,b):
    for i in range(2*n):
        if a[i] != b[i]:
            return False
    return True

def main():
    n = int(input())
    m = 2*n
    x = [i for i in range(m)]
    a = list(map(int,input().split()))
    for i in range(m):
        a[i] = a[i]-1
    steps = 0
    if cmp(n,a,x):
        print(steps)
        return 0
    ans = m*3
    for i in range(m):
        if i % 2 == 0:
            x = op1(n,x)
        if i % 2 == 1:
            x = op2(n,x)
        if cmp(n,a,x):
            steps = i + 1
            ans = min(steps, ans)
    x = [i for i in range(m)]
    for i in range(m):
        if i % 2 == 1:
            x = op1(n,x)
        if i % 2 == 0:
            x = op2(n,x)
        if cmp(n,a,x):
            steps = i + 1
            ans = min(steps, ans)
    if ans <= m:
        print(ans)
    else:    
        print(-1)

if __name__ == "__main__":
    input = sys.stdin.readline
    main()