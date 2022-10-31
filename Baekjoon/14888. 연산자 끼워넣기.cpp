//https://www.acmicpc.net/problem/14888
//14888. 연산자 끼워넣기(Silver 1, 백트래킹)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define endl "\n"
#define INF 999999
#define ll long long

using namespace std;

int N;
int arr[100];
int op[4];
int max_v = -1000000001, min_v = 1000000001;

void dfs(int v, int idx) {
    if(idx == N - 1) {
        max_v = max(max_v, v);
        min_v = min(min_v, v);
        return;
    }

    if(op[0] != 0) {
        op[0]--;
        dfs(v + arr[idx + 1], idx + 1);
        op[0]++;
    }
    if(op[1] != 0) {
        op[1]--;
        dfs(v - arr[idx + 1], idx + 1);
        op[1]++;
    }
    if(op[2] != 0) {
        op[2]--;
        dfs(v * arr[idx + 1], idx + 1);
        op[2]++;
    }
    if(op[3] != 0) {
        op[3]--;
        dfs(v / arr[idx + 1], idx + 1);
        op[3]++;
    }
    return;
}

int main()  
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];
    for(int i = 0; i < 4; i++) cin >> op[i];
    
    //SOLVE
    dfs(arr[0], 0);

    //OUTPUT
    cout << max_v << endl << min_v << endl;
    
}
//백트래킹 마스터하기!