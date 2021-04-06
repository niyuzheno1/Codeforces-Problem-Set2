import sys
import argparse
import math
from bisect import bisect_left


def main():
    maxn =  30010
    prime = [1]* maxn
    allprime = []
    def testgood(x, d):
        p = []
        for y in range(0, len(allprime)):
            if x % allprime[y]  == 0:
                p.append(allprime[y])
            if x < allprime[y]:
                break
        if len(p) <= 3:
            return False
        for i in range(0, len(p)-1):
            if(p[i+1]-p[i] < d):
                return False
        return True
    for i in range(2, maxn):
        for j in range(2, int(math.sqrt(i))+1):
            if i % j == 0:
                prime[i] = 0
    for i in range(2, maxn):
        if prime[i] == 1:
            allprime.append(i)
    for _ in range(0,int(input())): 
        d = int(input())
        y = bisect_left(allprime,1+d)
        z = bisect_left(allprime,allprime[y]+d)
        ans = allprime[y]*allprime[z]
        # for j in range(6, int(ans)):
        #     if testgood(j, d) == True:
        #         print("---" + j + "---")
        print(ans)


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()