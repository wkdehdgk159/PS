//https://www.acmicpc.net/problem/2281
//2281. 데스노트(Gold 4, DP)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define endl "\n"
#define INF 999999999
#define ll long long

using namespace std;

int N, M;
int arr[1000];
int dp[1000]; //dp[i]는 i번째 단어가 줄의 시작에 배치되었을 때의 최소값. dp[0]가 우리가 원하는 답

int cal(int idx) {
    if(idx == N - 1) return dp[idx] = 0;
    if(dp[idx] != -1) return dp[idx];

    dp[idx] = INF;

    //현재 인덱스의 이름을 맨 앞에 두고 뒤에 올 수 있는 모든 경우의 수를 체크
    int rest = M;
    for(int i = idx; i < N; i++) {
        //현재 들어온 글자 수 만큼 빼주고
        rest -= arr[i];
        if(rest < 0) break;
        dp[idx] = min(dp[idx], rest * rest + cal(i+1));
        //현재 인덱스 이후 모든 글자를 한 줄에 이어넣었단 이야기는 0
        if(i == N - 1) dp[idx] = 0;
        //한 이름 넣었으면 띄어쓰기 고려
        rest--;
    }
    return dp[idx];
}

int main()  
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> arr[i];

    //SOLVE
    memset(dp, -1, sizeof(dp)); //memset은 0이나 -1만 되는 것 주의
    

    //OUTPUT
    cout << cal(0);
}
//문제가 쉬워보이는데 어려워서 블로그를 참조했다.
//dp[i]를 정의하는 과정이 너무 어려웠고 1차원이라고 생각을 못한게 아쉬웠따.