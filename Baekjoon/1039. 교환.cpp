//https://www.acmicpc.net/problem/1039
//1039. 교환(Gold 3, BFS, 완전탐색, set)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>

#define endl "\n"
#define INT_INF 2147483647
#define LL_INF 9223372036854775807
#define ll long long
using namespace std;

int K, M, ans = 0;
string N;

void bfs() {
    queue<string> q;
    q.push(N);

    //K번 반복
    for(int i = 1; i <= K; i++) {
        //q의 사이즈가 변할 것이기 때문에 미리 지정
        int size = q.size();
        set<string> visited;

        for(int j = 0; j < size; j++) {
            string tmp = q.front();
            q.pop();

            for(int a = 0; a < M-1; a++) {
                for(int b = a + 1; b < M; b++) {
                    //첫번째 숫자와 바꾸려는 수가 0이라면 불가하므로 skip
                    if(a == 0 && tmp[b] == '0') continue;

                    swap(tmp[a], tmp[b]);
                    //처음 만들어진 경우의 수
                    if(visited.find(tmp) == visited.end()) {
                        //반복이 K번째라면 정답 후보
                        if(i == K) {
                            ans = max(ans, stoi(tmp));
                        }
                        q.push(tmp);
                        visited.insert(tmp);
                    }
                    //원상복구
                    swap(tmp[a], tmp[b]);
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    cin >> N >> K;

    //SOLVE
    M = N.length();
    //in impossible case print -1
    if(M == 1 || (M == 2 && N[M-1] == '0')) {
        cout << -1;
        return 0;
    }

    bfs();

    //OUTPUT
    cout << ans;
}
//엄청 좋은 문제같다 bfs일줄은 상상도 못했다