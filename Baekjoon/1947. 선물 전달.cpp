//https://www.acmicpc.net/problem/1947
//1947. 선물 전달(Gold 3, DP, 완전순열)

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
ll dp[1000001];

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
    dp[2] = 1;
    for(int i = 3; i <= N; i++) {
        dp[i] = (i-1) * (dp[i - 1] + dp[i - 2]);
        dp[i] %= MOD; 
    }

    //OUTPUT
    cout << dp[N];
}
//abc에서 d가 추가되었을 때 (1) d와 a가 선물을 교환했다면 bc가 교환하면 되니 dp[2] (2) d의 선물이 a에게 갔으나 a는 d에게 가지
//않았다면 이제 bca라는 조합을 선물이 겹치지 않게 조합해야 하는 것이니 dp[3]
//(위에서 bca를 조합해야 한다 말하는 것은 (2)조건으로 인해 d는 a의 선물을 받을 수 없다. 그래서 d를 임시로 a로 취급하는 것)
//이런 경우가 a,b,c 각각 있을테니 (n-1)을 곱해준다
//추후에 검색해보니 완전순열이라는 개념이 따로 있다고 한다(자신의 모자를 벗어두었다가 쓰는데 자신의 것이 아닌 경우의 수)