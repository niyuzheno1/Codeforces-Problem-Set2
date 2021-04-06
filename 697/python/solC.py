import sys
import argparse

def solve():
    a,b, k = list(map(int,input().split()))
    A = list(map(int,input().split()))
    B = list(map(int,input().split()))
    u = []
    for i in range(k):
        u.append((A[i],B[i]))
    u = sorted(u)
    for i in range(k):
        A[i] = u[i][0]
        B[i] = u[i][1]
    ans = [0]*k
    fa = [0]*(b+1)
    fb = [0]*(b+1)

    batch = 1
    csum = 0 
    for i in range(1,k):
        if A[i-1] != A[i]:
            csum += batch
            batch = 0
            for j in range(i-1, -1, -1):
                if A[j] == A[i-1]:
                    fa[B[j]] = fa[B[j]] + 1
                else:
                    break
        batch = batch + 1
        ans[i] = csum-fa[B[i]]      
    # batch = 1
    # csum = 0
    # for i in range(k-2,-1,-1):
    #     if A[i+1] != A[i]:
    #         csum += batch
    #         batch = 0
    #         for j in range(i+1, k):
    #             if A[j] == A[i+1]:
    #                 fb[B[j]] = fb[B[j]] + 1
    #             else:
    #                 break
    #     batch = batch + 1
    #     ans[i] += csum-fb[B[i]]
    return sum(ans)


def main():
    for _ in range(int(input())):
        print(solve())


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('--file', dest='filename', default=None)
    args = parser.parse_args()
    if args.filename is not None:
        sys.stdin = open(args.filename)
    main()