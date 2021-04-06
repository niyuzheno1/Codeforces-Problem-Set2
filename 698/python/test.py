import sys
import argparse

def test():
    for _ in range(int(input())):
        n = int(input())
        a = list(map(int,input().split()))
        n = 2 * n
        d = []
        for i in range(0, n):
            diff = 0
            for j in range(0,n):
                diff += abs(a[i]-a[j])
            d.append(diff)
        print(d) 
def main():
    test()



if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()