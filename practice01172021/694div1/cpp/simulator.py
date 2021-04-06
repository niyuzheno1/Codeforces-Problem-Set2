import sys
import argparse

def prev(x, n):
    return (x+n-1)%n

def next(x, n):
    return (x+1)%n

def step(a, x):
    n = len(a)
    cards = [0]*n
    for i in range(0,n):
        if x == i: # imposter
            cards[next(i,n)] += a[i]
        else:
            cards[prev(i,n)] += a[i]//2
            cards[next(i,n)] += (a[i]+1)//2
    return cards

def main():
    n = 100000
    k = 20
    x = 18236
    a = [k ]*n
    print(" 0 : {}".format(a))
    for i in range(0, 1000):
        a=step(a, x)
        print("{} : {}".format(i+1,a))


        

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()