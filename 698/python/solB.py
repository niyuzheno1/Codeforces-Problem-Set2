import sys
import argparse

def contain(x, d):
    x = str(x)
    n = len(x)
    d = str(d)
    for i in range(n):
        if x[i] == d:
            return True
    return False

def main():
    li = {}
    for i in range(2, 10):
        u = {}
        for j in range(0,i):
            u[j] = 0
            for k in range(0, 20):
                if contain(j + k *i, i):
                    u[j] = j + k *i
                    break
        li[i] = u
    for _ in range(int(input())):
        n, d = list(map(int,input().split()))
        a = list(map(int,input().split()))
        for i in range(n):
            if a[i] % d == 0:
                print("YES")
                continue
            if li[d][a[i]%d] <= a[i]:
                print("YES")
                continue
            print("NO")
    

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()