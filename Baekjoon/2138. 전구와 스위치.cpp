//https://www.acmicpc.net/problem/2138
//2138. 전구와 스위치(Gold 5, 그리디)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define endl "\n"
#define INF 999999
#define ll long long

using namespace std;

int N, ans1 = 1, ans2 = 0;
int bulb[2][100001];
int target[100001];

int neg(int i) {
    if(i == 0) return 1;
    else return 0;
}
void swit(int n, int idx) {
    if(idx == 0) {
        bulb[n][idx] = neg(bulb[n][idx]);
        bulb[n][idx + 1] = neg(bulb[n][idx + 1]);
        return;
    }
    if(idx == N - 1) {
        bulb[n][idx] = neg(bulb[n][idx]);
        bulb[n][idx - 1] = neg(bulb[n][idx - 1]);
        return;
    }
    bulb[n][idx - 1] = neg(bulb[n][idx - 1]);
    bulb[n][idx] = neg(bulb[n][idx]);
    bulb[n][idx + 1] = neg(bulb[n][idx + 1]);
    return;
}

int main()  
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    string s;
    cin >> N;
    cin >> s;
    for(int i = 0; i < N; i++) {
        bulb[0][i] = s[i] - '0';
        bulb[1][i] = s[i] - '0';
    }
    cin >> s;
    for(int i = 0; i < N; i++) {
        target[i] = s[i] - '0';
    }
    //SOLVE
    //0번째 스위치를 키는 경우
    swit(0,0);
    for(int i = 1; i < N; i++) {
        if(bulb[0][i - 1] != target[i - 1]) {
            swit(0, i);
            ans1++;
        }
    }
    if(bulb[0][N-1] != target[N-1]) ans1 = -1;

    //0번째 스위치를 키지 않는 경우
    for(int i = 1; i < N; i++) {
        if(bulb[1][i - 1] != target[i - 1]) {
            swit(1, i);
            ans2++;
        }
    }
    if(bulb[1][N-1] != target[N-1]) ans2 = -1;

    int ans;
    if(ans1 >= 0 && ans2 >= 0) ans = min(ans1, ans2);
    else ans = max(ans1, ans2);
    cout << ans;
}