//https://www.acmicpc.net/problem/2229
//2229. 조 짜기(Gold 5, DP)

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
int dp[1001], arr[1001]; //dp[i]는 i부터 맨 끝까지의 최대값 Top-down

int dfs(int idx) {
    if(idx == N+1) return 0;
    if(dp[idx] != -1) return dp[idx];

    int tmin = INF, tmax = -1;

    for(int i = idx; i <= N; i++) {
        tmin = min(tmin, arr[i]);
        tmax = max(tmax, arr[i]);
        dp[idx] = max(dp[idx], tmax - tmin + dfs(i + 1));
    }

    return dp[idx];
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
        cin >> arr[i];
    }

    //SOLVE
    memset(dp, -1, sizeof(dp));

    //OUTPUT
    cout << dfs(1);
}