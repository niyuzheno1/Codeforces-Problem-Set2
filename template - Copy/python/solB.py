import sys
import argparse


def main():
    input = sys.stdin.readline
    for _ in range(int(input())):
        d = list(map(int,input().split()))
        a = list(map(int,input().split()))
        b = list(map(int,input().split()))
        c = []
        
        A, B, n = d
        for i in range(n):
            c.append((a[i],b[i]))
        c = sorted(c)
        
        flag = True
        for i in range(n):
            u = (c[i][1] + A - 1) // A
            B -= u * c[i][0]
            if i == n-1:
                B += c[i][0]
            if B <= 0:
                flag = False
                break
        if flag == False:
            print("NO")
        else:
            print("YES")

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()