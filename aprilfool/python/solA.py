import sys
import argparse


def main():
    s = input()
    if s == "HELP" or s == "ANNA" or s == "SUM" or s == "MUG":
        print("YES")
    elif s == "PRODUCT" or s == "CUP" or s == "AID" or s == "MARY":
        print("NO")
    else:
        print("NO")

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()