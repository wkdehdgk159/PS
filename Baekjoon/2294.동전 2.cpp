//https://www.acmicpc.net/problem/2294
//2294. 동전 2(Gold 5, DP)

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
int dp[10001]; //dp[i]는 i원을 만들 수 있는 동전의 최수 개수
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
    dp[0] = 0;
    for(int i = 1; i <= k; i++) {
        dp[i] = -1;
    }
    
    //SOLVE
    //큰 동전부터 비교해주기 위해 오름차순 정렬
    for(int i = 1; i <= k; i++) {
        for(int j = 0; j < n; j++) {
            if(i - cv[j] >= 0 && dp[i - cv[j]] != -1) {
                if(dp[i] == -1) dp[i] = dp[i - cv[j]] + 1;
                else dp[i] = min(dp[i], dp[i - cv[j]] + 1);
            }
        }
    }
    
    //OUTPUT
    cout << dp[k];
}
//간단한 점화식 문제