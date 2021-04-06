import sys
import argparse
import math

def eval2(x,a,b):
    if b+x <= 1:
        return 10000000000000000
    if x < 0:
        return 10000000000000000
    def exper(x,a):
        ans = 0
        xx = 1
        while xx <= a:
            xx *= x
            ans = ans + 1
        return ans
    return exper(x+b, a) + x
def eval(x, a, b):
    if b+x <= 1:
        return 10000000000000000
    return math.ceil(math.log(a) / math.log(b+x)) + x


def main():
    for _ in range(int(input())):
        a, b = list(map(int,input().split()))
        ans = 0
        if b == 1:
            ans = ans + 1
            b = 2
        l, r = 0, 2*b
        lb = eval2(0,a,b)
        rb = eval2(2*b, a, b)
        while r-l > 0.1:
            d = r-l
            mid1 = d*1.0/3.0 + l
            mid2 = d*2.0/3.0 + l
            mb1 = eval2(mid1, a, b)
            mb2 = eval2(mid2, a, b)
            if mb1 < mb2:
                r = mid2
            else:
                l = mid1
        q = eval2(int((l+r)/2.0-2),a,b)
        for i in range(-1,2):
            q = min(q, eval2(int((l+r)/2.0+i),a,b))
        print(q+ans)




if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()