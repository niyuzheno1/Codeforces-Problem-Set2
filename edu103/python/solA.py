import sys
import argparse


def main():
    for _ in range(int(input())):
        n, k = list(map(int,input().split()))
        def check(x):
            i = n 
            j = k
            if x * i // j != (x + i-1)// j or (x * i % j ==0) or ((x + i-1)% j ==0) :
                return True
            return False
        
        if n % k == 0:
            print("1")
        else:
            u = k // n
            v = k // n + 1
            w = k // n + 2
            if u > 0:
                if check(u):
                    print(u)
                    continue
            if v > 0:
                if check(v):
                    print(v)
                    continue
            if w > 0:
                if check(w):
                    print(w)
                    continue
            

            



if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()