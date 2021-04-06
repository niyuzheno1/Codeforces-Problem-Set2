import sys
import argparse


def main():
    for _ in range(int(input())):
        x = int(input())
        c = x**(1./3.)
        u = int(c)+2
        i = 0
        flag = False
        while (u-i) > 0 and i < 2000:
            v = x - (u-i)**3
            v = v**(1./3.)
            v = int(v.real)
            if (u-i)**3 + v**3 == x:
                flag = True
            i = i + 1
        if flag:
            print("YES")
        else:
            print("NO")
        

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()