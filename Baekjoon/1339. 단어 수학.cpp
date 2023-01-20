//https://www.acmicpc.net/problem/1339
//1339. 단어 수학(Gold 4, 그리디)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

#define endl "\n"
#define INT_INF 2147483647
#define LL_INF 9223372036854775807
#define ll long long

using namespace std;

int N;
ll ans = 0;
int arr[26];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    cin >> N;
    string tmp;
    int c;

    //SOLVE
    memset(arr, 0, sizeof(arr));
    for(int i = 0; i < N; i++) {
        cin >> tmp;
        int str_len = tmp.length();
        int v = 1;
        for(int i = 0; i < str_len - 1; i++) v *= 10;
        for(int i = 0; i < str_len; i++) {
            c = int(tmp[i]) - 65;
            arr[c] += v;
            v /= 10;
        }
    }
    
    //내림차순으로 정렬
    sort(arr, arr + 26, greater<int>());
    int k = 9, idx = 0;
    while(arr[idx] != 0) {
        ans += k * arr[idx];
        idx++;
        k--;
    }
    

    //OUTPUT
    cout << ans;
}