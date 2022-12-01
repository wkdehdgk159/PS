//https://www.acmicpc.net/problem/1890
//1890. 점프(Silver 1, DP)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define endl "\n"
#define INF 999999999
#define ll long long

using namespace std;

ll dp[101][101]; //dp[i][j]는 (i,j)에서 목표지점으로 갈 수 있는 경로의 수
int board[101][101];
int N;

ll cal(int x, int y) {
    if(x == N && y == N) return 1;
    if(dp[x][y] != -1) return dp[x][y];

    dp[x][y] = 0;
    
    if(x + board[x][y] <= N) dp[x][y] += cal(x + board[x][y], y);
    if(y + board[x][y] <= N) dp[x][y] += cal(x, y + board[x][y]);

    return dp[x][y];
}

int main()  
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    cin >> N;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> board[i][j];
        }
    }

    //SOLVE
    memset(dp, -1, sizeof(dp));

    //OUTPUT
    cout << cal(1, 1);
}
//몸풀기 문제이지만 이걸 bottom-up으로 고민해보니 고민되는 부분이 있었다.
//DP[i+board[i][j]] += DP[i][j] 이런 식으로하면 된다.