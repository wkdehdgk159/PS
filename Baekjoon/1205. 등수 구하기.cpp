//https://www.acmicpc.net/problem/1205
//1205. 등수 구하기(Silver 4, 구현)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define endl "\n"
#define INF 999999999
using namespace std;

int N, P;
int Rank[50];
int score;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    cin >> N >> score >> P;
    for(int i = 0; i < P; i++) {
        cin >> Rank[i];
    }

    //SOLVE
    int ans = -1;
    sort(Rank, Rank + P, greater<int>());

    if(N == P && Rank[P-1] == score ) {
        cout << ans;
        return 0;
    }
    for(int i = 0; i < P; i++) {
        if (Rank[i] == score) {
            ans = i + 1;
            break;
        }
        if (Rank[i] < score) {
            ans = i + 1;
            break;
        }
    }
    //OUTPUT
    cout << ans;
}