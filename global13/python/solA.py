import sys
import argparse


def main():
    for _ in range(int(input())):
        n,u,v = list(map(int,input().split()))
        a = list(map(int,input().split()))
        good = True
        good2 =  True
        for i in range(0,n-1):
            if abs(a[i]-a[i+1]) >= 2:
                good = False
            if abs(a[i]-a[i+1]) == 1:
                good2 = False
        if good == False:
            print(0)
            continue
        if good2:
            print(min(u+v,2*v))
        else:
            print(min(u,v))
        
        

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()