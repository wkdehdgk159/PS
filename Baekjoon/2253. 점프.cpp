//https://www.acmicpc.net/problem/2253
//2253. 점프(Gold 4, DP)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define endl "\n"
#define INF 999999999
#define ll long long
#define MOD 1000000000

using namespace std;

int N, M;
int dp[10001][151]; //dp[i][j]는 i번째 돌에 j의 점프력으로 뛰었을 때의 최소 점프 횟수
bool check[10001];
int ans = INF;

int main()  
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    cin >> N >> M;
    memset(check, 0, sizeof(check));
    int tmp;
    for(int i = 0; i < M; i++) {
        cin >> tmp;
        check[tmp] = 1;
    }

    //SOLVE
    for(int i = 0; i <= N; i++) {
        for(int j = 0; j <= 150; j++) {
            dp[i][j] = INF;
        }
    }

    dp[1][0] = 0, dp[1][1] = 0, dp[2][1] = 1;
    for(int i = 2; i <= N; i++) {
        if(check[i]) continue;
        for(int j = 1; j <= 150; j++) {
            if(i - j >= 2 && !check[i-j]) {
                dp[i][j] = min(dp[i][j], dp[i-j][j+1] + 1);
                dp[i][j] = min(dp[i][j], dp[i-j][j] + 1);
                dp[i][j] = min(dp[i][j], dp[i-j][j-1] + 1);
            }
        }
    }

    //OUTPUT
    for(int i = 1; i <= 150; i++) ans = min(ans, dp[N][i]);
    if(ans == INF) ans = -1;
    cout << ans;
}
//점화식 + 나올 수 있는 점프력의 최대치를 잘 고려하면 된다.