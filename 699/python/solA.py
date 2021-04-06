import sys
import argparse


def main():
    for _ in range(int(input())):
        px, py = list(map(int,input().split()))
        s = input()
        a = {'R' : 0, 'L' : 0, 'U' : 0, 'D' : 0}
        for i in range(0,len(s)):
            a[s[i]] = a[s[i]]+1
        flag = True
        if px > 0 and a['R'] < px:
            flag = False
        if px < 0 and -a['L'] > px:
            flag = False
        if py > 0 and a['U'] < py:
            flag = False
        if py < 0 and -a['D'] > py:
            flag = False
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