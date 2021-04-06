import sys
import argparse
import math

def main():
    a = list(map(int,input().split()))
    def check(x,y):
            delta = x - y
            if delta < 0:
                return False
            sq = math.sqrt(delta)
            if sq == 0:
                return False
            sqq = math.sqrt(sq)
            sqq = int(sqq)
            if sqq**4 == x - y:
                return True
            else:
                return False

    for i in range(1, 100):
        for j in range(1,100):
            for k in range(1,100):
                for l in range(1,100):
                    if check(a[0]*i,a[1]*j) == False:
                        continue
                    if check(a[1]*j,a[2]*k) == False:
                        continue
                    if check(a[2]*k,a[3]*l) == False:
                        continue
                    print(i,j,k,l)
                

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()