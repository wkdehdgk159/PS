//https://www.acmicpc.net/problem/16298
//16298. 뱀과 사다리 게임(Gold 5, BFS???)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

#define endl "\n"
#define INT_INF 2147483647
#define LL_INF 9223372036854775807
#define ll long long
using namespace std;

int board[101];
bool visited[101];

void bfs(int x, int cnt) {

    queue<pair<int, int> > q;
    q.push({x, cnt});

    while(!q.empty()) {

        int cx = q.front().first;
        int cc = q.front().second;
        q.pop();

        for(int i = 1; i <= 6; i++) {
            
            int nx = cx + i;

            if(nx == 100) {
                cout << cc + 1;
                return;
            }

            else if(nx < 100) {
                while(board[nx] != 0) {
                    nx = board[nx];
                }

                if(!visited[nx]) {
                    q.push({nx, cc + 1});
                    visited[nx] = 1;
                }
            }
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //INPUT
    int N, M;
    cin >> N >> M;

    int x, y, u, v;
    for(int i = 0; i < N; i++)  {
        cin >> x >> y;
        board[x] = y;
    }

    for(int i = 0; i < M; i++)  {
        cin >> u >> v;
        board[u] = v;
    }

    //SOLVE
    bfs(1, 0);

    //OUTPUT
}
/*
1. bfs(현재 칸, 주사위 수, cnt) 하면 나오지 않을까?
*/