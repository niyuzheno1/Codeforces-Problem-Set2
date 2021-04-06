import sys
import argparse


def main():
    for _ in range(int(input())):
        n = int(input())
        a = list(map(int,input().split()))
        r = {0 : 0, 1 : 0, 2:0}
        for i in range(n):
            r[a[i] % 3] = r[a[i] % 3] + 1
        cnt = 1031244214
        avg = 0
        for i in range(3):
            avg += r[i]
        avg /= 3
        maxid = 0
        for i in range(3):
            if r[i] > r[maxid]:
                maxid = i
        cnt = 0
        for i in range(3):
            while r[i] < avg:
                if i > maxid:
                    cnt += (i-maxid)*min(avg-r[i],(r[maxid]-avg))
                    r[i] = r[i]+min(avg-r[i],(r[maxid]-avg))
                else:
                    cnt += (3 - (maxid-i)) *min(avg-r[i], (r[maxid]-avg))
                    r[i] = r[i]+min(avg-r[i],(r[maxid]-avg))
                r[maxid] -= (avg-r[i])
                r[maxid] = max(r[maxid],avg)
                for j in range(3):
                    if r[j] > r[maxid]:
                        maxid = j
        print(int(cnt))
if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()