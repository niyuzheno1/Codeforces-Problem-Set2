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

def main():
    for _ in range(int(input())):
        n, k = list(map(int,input().split()))
        
        k = k-1
        if n % 2 == 0:
            print((0 + k) % n+1 )
        else:
            k %= ((n-1) + (n-2)*(n-1)//2)
            first = (n+1)//2-1
            if k < n-1:
                if k < first:
                    print(k+1)
                    continue
                else:
                    print(k+2)
            else:
                k -= n-1
                u = k//(n-2)
                v = k % (n-2)
                first = u
                second = (n+1)//2 + u
                if v < first:
                    print(v+1)
                elif v >= first and v < second:
                    print(v+2)
                else:
                    print(v+3)



if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()