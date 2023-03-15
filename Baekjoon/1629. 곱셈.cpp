//https://www.acmicpc.net/problem/1629
//1629. 곱셈(Silver 1, 분할정복을 통한 거듭제곱)

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

ll A, B, C, ans = 0;

ll solve(ll a, ll b) {
    if(b == 0) return 1;
    if(b == 1) return a % C;

    ll res = solve(a, b/2) % C;

    if(b % 2 == 1) {
        return res * res % C * a % C;
    }
    else {
        return res * res % C;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    cin >> A >> B >> C;

    //SOLVE
    ans = solve(A, B);

    //OUTPUT
    cout << ans;
}