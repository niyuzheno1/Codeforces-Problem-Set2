import sys

def op1(n, x):
    # 0 -> 1, 2 -> 3
    for i in range(0,n):
        u = 2*i
        v = 2*i+1
        t1 = x[u]
        x[u] = x[v]
        x[v] = t1
    return x

def op2(n,x):
    # 0 -> n 1 -> n+1
    for i in range(0,n):
        u = i
        v = i+n
        t1 = x[u]
        x[u] = x[v]
        x[v] = t1
    return x

def main():
    n, q  =list(map(int,input().split()))
    for _ in range(q):
        m = 2*n
        x = [i for i in range(m)]
        b = list(map(int,input().split()))
        for i in range(len(b)):
            if b[i] == 0:
                x = op1(n,x)
            if b[i] == 1:
                x = op2(n,x)
        print(x)

    pass

if __name__ == "__main__":
    input = sys.stdin.readline
    main()