import sys
import argparse

def test():
    for _ in range(int(input())):
        n = int(input())
        a = list(map(int,input().split()))
        n = 2 * n
        d = []
        for i in range(0, n):
            diff = 0
            for j in range(0,n):
                diff += abs(a[i]-a[j])
            d.append(diff)
        print(d) 
def gen(u, p):
    s = 0
    flag = True
    a = []
    for i in range(len(u)):
            if (u[i]-2*s) % p != 0:
                flag = False
            if (u[i]-2*s) <= 0:
                flag = False
            x = (u[i]-2*s)//p
            s += x
            a.append(x)
            p = p - 2
    if flag == False:
        return None
    else:
        return a
def main():
    for _ in range(int(input())):
        n = int(input())
        d = list(map(int,input().split()))
        flag = True
        p =  2*n
        s = 0
        ax = {}
        a = {0: [], 1:[]}
        d = sorted(d, reverse=True)
        for i in range(0, len(d)):
            a[i%2].append(d[i])
        a0 = gen(a[0],p)
        a1 = gen(a[1],p)
        
        if a0 == None or a1 == None:
            flag = False
        else:
            for i in range(0, len(a0)):
                if a0[i] != a1[i]:
                    flag = False
        if flag == False:
            print("NO")
            continue
        else:
            print("YES")


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()