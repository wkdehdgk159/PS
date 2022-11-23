//https://www.acmicpc.net/problem/1562
//1562. 계단 수(Gold 1, DP)

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

int N;
int dp[101][10][1 << 10]; //dp[i][j][k]는 i자리 수 + j로 끝나는 수 + 비트마스킹을 이용해 k에 해당하는 자연수가 나온 경우
int BM = 1 << 10;
ll ans = 0;

int main()  
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    cin >> N;

    //SOLVE
    memset(dp, 0, sizeof(dp));
    //base case 0인 경우는 제외 주의
    for(int i = 1; i < 10; i++) dp[1][i][1<<i] = 1;

    for(int i = 2; i <= N; i++) {
        for(int j = 0; j < 10; j++) {
            for(int k = 0; k < BM; k++) {
                //(1 << j)와 k를 or 해주어 마지막 끝나는 수 j가 반영될 수 있게끔
                int bit = k | (1 << j);
                if(j > 0) dp[i][j][bit] = (dp[i][j][bit] + dp[i-1][j-1][k]) % MOD;
                if(j < 9) dp[i][j][bit] = (dp[i][j][bit] + dp[i-1][j+1][k]) % MOD;
            }
        }
    }
    
    //모든 비트가 켜진 경우의 계단 수만 구하는 것이므로 BM-1 친구들만 더해준다.
    for(int i = 0; i < 10; i++) {
        ans = (ans + dp[N][i][BM-1]) % MOD;
    }


    //OUTPUT
    cout << ans;
}
//블로그를 보고도 이해하는 데 한참이 걸렸다.
//나중에 다시푼다 했을 때 자신이 없다