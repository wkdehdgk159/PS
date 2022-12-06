//https://www.acmicpc.net/problem/1965
//1965. 상자넣기(Silver 2, DP) 

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define endl "\n"
#define INF 999999999
#define ll long long

using namespace std;

int n;
int ans = 0;
int dp[1000];
int arr[1000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    //SOLVE
    for(int i = 0; i < n; i++) {
        dp[i] = 1;
    }

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[j] > arr[i]) dp[j] = max(dp[j], dp[i] + 1);
        }
    }
    for(int i = 0; i < n; i++) {
        ans = max(ans, dp[i]);
    }
    //OUTPUT
    cout << ans;
}
//LIS