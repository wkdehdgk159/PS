//https://www.acmicpc.net/problem/5582
//5582. 공통 부분 문자열(Gold 5, DP)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define endl "\n"
#define INF 999999999
#define ll long long

using namespace std;

string str1, str2;
int dp[4010][4010];
int ans = 0;

int main()  
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    memset(dp, 0, sizeof(dp));
    cin >> str1 >> str2;

    int len1 = str1.length(), len2 = str2.length();

    //SOLVE
    for(int i = 0; i < len1; i++) {
        for(int j = 0; j < len2; j++) {
            if(str1[i] == str2[j]) {
                if(i == 0 || j == 0) dp[i][j] = 1;
                else dp[i][j] = dp[i-1][j-1] + 1;
                ans = max(ans, dp[i][j]);
            }
        }
    }

    //OUTPUT
    cout << ans;
} 