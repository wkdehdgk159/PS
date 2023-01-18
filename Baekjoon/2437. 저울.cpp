//https://www.acmicpc.net/problem/2437
//2437. 저울(Gold 2, 그리디)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define endl "\n"
#define INT_INF 2147483647
#define LL_INF 9223372036854775807
#define ll long long

using namespace std;

int N, ans = 1;
int weight[1000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    cin >> N;
    for(int i = 0; i < N; i++) cin >> weight[i];

    //SOLVE
    sort(weight, weight + N);
    if(weight[0] > 1) ans = 1;
    else {
        int total = weight[0];
        for(int i = 1; i < N; i++) {
            if(total + 1 < weight[i]) {
                ans = total + 1;
                break;
            }
            total += weight[i];
            //마지막까지 당도한다면
            if(i == N - 1) ans = total + 1;
        }
    }

    //OUTPUT
    cout << ans;
}