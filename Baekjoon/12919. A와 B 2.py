#https://www.acmicpc.net/problem/12919
#12919. A와 B 2 (Gold5, 재귀)

from sys import stdin
#두가지 경우의 수 T의 맨 뒤 A를 지우거나, 문자열을 뒤집은 후 맨 뒤 B를 지운다.
def check(S, T):
    if len(S) == len(T):
        if(S == T):
            return 1
        return

    #맨 뒤가 B이면 뒤집은 후 B를 지우는 방법 뿐
    if T[-1] == "B":
        if T[0] == "A":
            return
        return check(S, T[:0:-1])
    else:
        if T[0] == "A":
            return check(S, T[:-1])
        else:
            return check(S, T[:0:-1]) or check(S, T[:-1])
    return

def main():
    # f = open("input.txt", 'r')
    # S = f.readline().strip()
    # T = f.readline().strip()
    S = stdin.readline().strip()
    T = stdin.readline().strip()
    if check(S, T):
        print(1)
    else:
        print(0)


if __name__ == "__main__":
    main()