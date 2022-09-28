#https://www.acmicpc.net/problem/22233
#22233. 가희와 키워드 (Silver 2, 해시, 문자열)

from sys import stdin

def main():
    # f = open("input.txt", 'r')
    # N, M = f.readline().strip().split(' ')

    N, M = stdin.readline().strip().split(' ')
    
    ans = int(N);
    KW = {}
    for _ in range(int(N)):
        KW[stdin.readline().strip()] = 1
    for _ in range(int(M)):
        tmp = stdin.readline().strip().split(',')
        for k in tmp:
            if k in KW.keys():
                if KW[k] == 1:
                    KW[k] = 0
                    ans = ans - 1
        print(ans)


if __name__ == "__main__":
    main()