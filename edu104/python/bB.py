import sys
import argparse

def compute(n,k):
    x = n-1
    y = 0
    a = [x+1]
    b = [y+1]
    for i in range(0, k+2):
        x = x-1
        if x < 0:
            x += n
        y = y+1
        y%=n
        if y == x:
            y = y + 1
        y%=n
        a.append(x+1)
        b.append(y+1) 
    #print(a)
    #print(b)
    print(b[k-1])
    #print(b[41])
def main():
    for _ in range(int(input())):
        n,k = list(map(int,input().split()))
        compute(n,k)
    

        

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()