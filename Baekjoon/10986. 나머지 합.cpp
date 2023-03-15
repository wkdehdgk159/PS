//https://www.acmicpc.net/problem/10986
//10986. 나머지 합(Gold 3, 누적합)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

#define endl "\n"
#define INT_INF 2147483647
#define LL_INF 9223372036854775807
#define ll long long
using namespace std;

ll N, M, ans = 0;
ll sumarr[1000000];
//sumarr의 나머지를 세는 배열
ll marr[1000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    cin >> N >> M;

    //SOLVE
    //누적합 계산
    ll sum = 0;
    ll A;
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        cin >> A;
        if(A % M == 0) cnt++;
        sum += A;
        sumarr[i] = sum;
    }

    //구간합 (sumarr[j] - sumarr[i-1]) & M = 0 이라면
    //(sumarr[j] % M) - (sumarr[i-1] % M) = 0 이므로 
    //(sumarr[j] % M) = (sumarr[i-1] % M)) 인 경우의 수를 찾자.
    for(int i = 0; i < N; i++) {
        marr[sumarr[i] % M]++;
    }
    for(int i = 0; i < M; i++) {
        //후보들 중 2개를 순서상관없이 고르는 경우의 수
        ans += marr[i] * (marr[i] - 1) / 2;
    }
    //marr[0]에 들어갔던 구간합은 자기 자신만으로도 해당되기 때문에 따로 더해줌
    ans += marr[0]; 

    //OUTPUT
    cout << ans;
}
//marr를 int로 선언하여 여러번 틀렸던 문제 N의 최대값이 10^6이라 int로 충분하다 생각했는데 marr[i] * marr[i] 에서 오버플로우가 발생할 수 있다.
//굳이 int를 쓰고 싶다면 곱셈 과정에서 1LL *  나 int64_t 같이 형변환을 임시로 시켜주자.
//누적합 문제는 항상 Prefix sum을 먼저 고려하자