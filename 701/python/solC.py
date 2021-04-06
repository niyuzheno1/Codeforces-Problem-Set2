import sys
import argparse
import math


def main():
    for _ in range(int(input())):
        x,y = list(map(int,input().split()))
        cnt = 0
        lower_b = min(math.floor(math.sqrt(x)),y)
        higher_b = lower_b+1
        while higher_b <= y:
            l, r = higher_b,  x+1
            le = x//(higher_b + 1)
            if le == 0:
                break
            while l < r:
                mid = (l+r)>>1
                if (x//(mid+1)) == le:
                    l = mid+1
                else:
                    r = mid-1
            mid = (l+r)>>1
            mid = max(mid-2, higher_b)
            while x//(mid+1) == le:
                mid = mid + 1
            cnt += (min(mid,y+1) - higher_b)*le
            higher_b = mid
        lower_b = lower_b - 1
        cnt += lower_b * (lower_b+1)//2
        print(cnt)

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()