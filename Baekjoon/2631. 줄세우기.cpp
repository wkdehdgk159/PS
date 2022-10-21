//https://www.acmicpc.net/problem/2631
//2631. 줄세우기(Gold 4, DP, LIS)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define endl "\n"
#define INF 999999
using namespace std;

int N;
int arr[200];
int dp[200];
int max_len = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
        dp[i] = 1;
    }

    //SOLVE
    //LIS를 찾은 후 나머지 친구들을 이동시키면 된다. 전체 길이 - LIS 길이
    for(int i = 1; i < N; i++) {
        for(int j = 0; j < i; j++) {
            if(arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        max_len = max(max_len, dp[i]);
    }

    // OUTPUT
    cout << N - max_len;

}
//추억의 LIS MSS 등등이 기억난다 복습해야겠다