//https://www.acmicpc.net/problem/1520
//1520. 내리막 길(Gold 3, DP, DFS)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define endl "\n"
#define INF 999999
#define ll long long

using namespace std;

int R, C;
int board[500][500];
int dp[500][500];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int dfs(int x, int y) {
    if(x == R - 1 && y == C - 1) return 1;
    if(dp[x][y] != -1) return dp[x][y];

    dp[x][y] = 0;
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
        if(board[x][y] > board[nx][ny]) {
            dp[x][y] += dfs(nx, ny); 
        }
    }
    return dp[x][y];
}

int main()  
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    cin >> R >> C;
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cin >> board[i][j];
            dp[i][j] = -1;
        }
    }
    
    //SOLVE
    dfs(0, 0);
    
    //OUTPUT
    cout << dp[0][0];
    
}
//dp의 핵심은 memoization을 통한 중복 제거인데 자꾸 점화식이라고 착각한다.
//탐색과 dp가 적절히 혼합된 좋은 문제였다.