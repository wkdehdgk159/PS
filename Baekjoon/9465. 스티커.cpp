//https://www.acmicpc.net/problem/9465
//9465. 스티커(Silver 1, DP)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define endl "\n"
#define INF 999999
#define ll long long

using namespace std;

int n, TC;
int dp[100000][2];//dp[i][j]는 i열 j행의 스티커를 골랐을 때 나오는 이때까지의 최대값
int sti[100000][2];

int main()  
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    cin >> TC;
    while(TC--) {
        //INPUT
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> sti[i][0];
        }
        for(int i = 0; i < n; i++) {
            cin >> sti[i][1];
        }

        //SOLVE
        memset(dp, 0, sizeof(dp));
        dp[0][0] = sti[0][0];
        dp[0][1] = sti[0][1];
        dp[1][0] = dp[0][1] + sti[1][0];
        dp[1][1] = dp[0][0] + sti[1][1];
        int ans = max(dp[1][0], dp[1][1]);
        for(int i = 2; i < n; i++) {
            dp[i][0] = max(dp[i-1][1], dp[i-2][1]) + sti[i][0];
            dp[i][1] = max(dp[i-1][0], dp[i-2][0]) + sti[i][1];

            if(ans < dp[i][0]) ans = dp[i][0];
            if(ans < dp[i][1]) ans = dp[i][1];
        }
        //OUTPUT
        cout << ans << endl;
    }
}