//https://www.acmicpc.net/problem/12865
//12865. 평범한 배낭(Gold 5, Knapsack)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define endl "\n"
#define INF 999999
#define ll long long

using namespace std;

int N, K;
pair<int, int> arr[101];//W, V
int dp[101][100001];
int ans = 0;

int main()  
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    cin >> N >> K;
    pair<int, int> tmp;
    for(int i = 1; i <= N; i++) {
        cin >> tmp.first >> tmp.second;
        arr[i] = tmp;
    }
    
    //SOLVE
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= K; j++) {
            int curw = arr[i].first;
            int curv = arr[i].second;
            //가방에 넣는 시도조차 못 하는 경우
            if(j < curw) dp[i][j] = dp[i-1][j];
            else {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-curw] + curv);
            }
        }
    }

    //OUTPUT
    cout << dp[N][K];
    
}