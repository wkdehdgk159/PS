//https://www.acmicpc.net/problem/2293
//2293. 동전 1(Gold 5, DP)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define endl "\n"
#define INF 999999
#define ll long long

using namespace std;

int n, k;
int dp[10001];
int cv[100];

int main()  
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> cv[i];
    }
    
    //SOLVE
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(int i = 0; i < n; i++) {
        for(int j = cv[i]; j <= k; j++) {
            dp[j] += dp[j - cv[i]];
        }
    }
    
    //OUTPUT
    cout << dp[k];
}
//간단한 점화식 문제