//https://www.acmicpc.net/problem/18291
//18291. 비요뜨의 징검다리 건너기(Gold 5, 분할정복을 통한 거듭제곱)

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

int T;
ll N, ans, d = 1000000007;

//2**(N-2)가 정답
ll solve(ll n) {
    if(n == 0) return 1;
    if(n == 1) return 2; 
    ll res = solve(n / 2) % d;
    if(n % 2 == 1) return res * res % d * 2 % d;
    else return res * res % d;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    cin >> T;

    //SOLVE
    for(int i = 0; i < T; i++) {
        cin >> N;
        if(N == 1) cout << 1 << endl;
        else cout << solve(N-2) << endl;
    }

    //OUTPUT
}