//https://www.acmicpc.net/problem/2133
//2133.타일 채우기(Gold 4, DP)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>

#define endl "\n"
#define INF 999999
#define ll long long

using namespace std;

int N, ans = 0;
int dp[30];

int main()  
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    cin >> N;

    //SOLVE
    //나올 수 있는 모양의 종류는 3x2일 때 3개 뒤에는 3 x 2n 일때마다 2개
    memset(dp, 0, sizeof(dp));
    if(N % 2 == 1) {
        cout << 0;
        return 0;
    }
    dp[0] = 1;
    dp[2] = 3;
    
    //이전 블럭에서 2를 붙여줄때만 3을 곱해주고 나머지는 2
    for(int i = 4; i <= N; i+=2) {
        for(int j = i; j > 0; j-=2) {
            if(j == 2) dp[i] += dp[i - j] * 3;
            else dp[i] += dp[i - j] * 2;
        }
    }

    //OUTPUT
    cout << dp[N];
}
//2개 블록이 추가될 때 생기는 새로운 케이스를 확인하진 못했지만 2로 때려맞췄다.