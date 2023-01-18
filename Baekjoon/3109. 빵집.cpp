//https://www.acmicpc.net/problem/3109
//3109. 빵집(Gold 2, DFS)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define endl "\n"
#define INT_INF 2147483647
#define LL_INF 9223372036854775807
#define ll long long

using namespace std;

int R, C, ans = 0;
bool visited[10000][500];
int dx[3] = {-1, 0, 1};
int dy[3] = {1, 1, 1};

bool dfs(int x, int y) {

    visited[x][y] = 1;
    //만약 끝에 도착하면 visited 처리 후 벡터 클리어 -> 다음 row 후보로
    if(y == C-1) {
        ans++;
        return true;
    }

    for(int i = 0; i < 3; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx > R-1 || ny > C-1) continue;
        if(!visited[nx][ny]) {
            if(dfs(nx, ny)) return true;
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    cin >> R >> C;
    char b;
    memset(visited, 0, sizeof(visited));
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cin >> b;
            if(b == 'x') visited[i][j] = 1;
        }
    }

    //SOLVE
    for(int i = 0; i < R; i++) {
        dfs(i, 0);
    }

    //OUTPUT
    cout << ans;
}