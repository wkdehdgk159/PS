//https://www.acmicpc.net/problem/1309
//1309. 동물원(Silver 1, DP) 

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define endl "\n"
#define INF 999999999
#define ll long long

using namespace std;

int N;
int dp[100001][3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    cin >> N;

    //SOLVE
    memset(dp, 0, sizeof(dp));
    dp[1][0] = 1, dp[1][1] = 1, dp[1][2] = 1;

    for(int i = 2; i <= N; i++) {
        dp[i][0] = (dp[i-1][0] + dp[i-1][1] + dp[i-1][2]) % 9901;
        dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % 9901;
        dp[i][2] = (dp[i-1][0] + dp[i-1][1]) % 9901;
    }

    //OUTPUT
    cout << (dp[N][0] + dp[N][1] + dp[N][2]) % 9901;
}
//실버 1 문제가 맞나..?
