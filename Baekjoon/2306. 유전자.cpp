//https://www.acmicpc.net/problem/2306
//2306. 유전자(Gold 3, DP)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define endl "\n"
#define INF 999999999
#define ll long long

using namespace std;

int dp[510][510]; //dp[i][j]는 i부터 j까지의 가장 긴 KOI 유전자 길이
string DNA;

int cal(int s, int e) {

    if(s >= e) return 0;
    if(dp[s][e] != -1) return dp[s][e];

    dp[s][e] = 0;
    //양끝이 이렇게 짝이면 안쪽의 최대 KOI 유전자 길이 + 2
    if((DNA[s] == 'a' && DNA[e] == 't') || (DNA[s] == 'g' && DNA[e] == 'c')) {
        dp[s][e] = max(dp[s][e], cal(s + 1, e - 1) + 2);
    }
    //
    for(int i = s; i < e; i++) {
        dp[s][e] = max(dp[s][e], cal(s, i) + cal(i + 1, e));
    }

    return dp[s][e];
}

int main()  
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    cin >> DNA;

    //SOLVE
    memset(dp, -1, sizeof(dp));

    //OUTPUT
    cout << cal(0, DNA.length() - 1);
}
//아이디어 떠올리는 것이 힘들었다.
//KOI 유전자끼리 붙은 것이라는 조건에서 cal(s, i) + cal(i + 1, e). 