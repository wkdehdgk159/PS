//https://www.acmicpc.net/problem/2467
//2467. 용액(Gold 5, 투포인터)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define endl "\n"
#define INF 999999999
using namespace std;

int N;
int liquid[100000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    cin >> N;
    memset(liquid, 0, sizeof(liquid));

    int idx = 0, ansl, ansr, min_sum = 2000000000;
    for(int i = 0; i < N; i++) {
        cin >> liquid[i];
    }

    //SOLVE
    //양쪽 끝에서 좁혀 오면서 투포인터
    int l = 0, r = N - 1;
    while(l < r) {
        int tmp_sum = liquid[l] + liquid[r];
        if(abs(tmp_sum) < min_sum) {
            min_sum = abs(tmp_sum);
            ansl = liquid[l];
            ansr = liquid[r];
        }
        if(tmp_sum < 0) l++;
        else r--;
    }

    //OUTPUT
    cout << ansl << " " << ansr;
}