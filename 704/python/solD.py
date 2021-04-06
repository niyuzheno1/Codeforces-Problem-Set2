import sys
import argparse


def main():
    a,b,k =  list(map(int,input().split()))
    if k > a:
        print("NO")
        return 
    print("YES")
    ansx = []
    ansy = []
    for i in range(b):
        ansx.append(1)
    for i in range(a):
        ansx.append(0)
    for i in range(b-1):
        ansy.append(1)
    for j in range(k):
        ansy.append(0)
    ansy.append(1)
    for j in range(a-k):
        ansy.append(0)
    print("".join(list(map(str,ansx))))
    print("".join(list(map(str,ansy))))
    
    

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()