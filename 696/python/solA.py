import sys
import argparse


def main():
    for _ in range(int(input())):
        n = int(input())
        a = input()
        ans = []
        last = -1
        now = 0
        for i in range(n):
            if a[i] == last:
                now ^= 1
                ans.append(now)
            else:
                if int(last) == 1 and now == 0:
                    now = 0
                else:
                    now = 1
                last = a[i]
                ans.append(now)
        print("".join(list(map(str,ans))))

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()