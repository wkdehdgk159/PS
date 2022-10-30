//https://www.acmicpc.net/problem/9663
//9663. N-Queen(Gold 4, 백트래킹)

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
int ans = 0;
int board[15];//board[r] = c;

bool promising(int rdx) {
    for(int i = 0; i < rdx; i++) {
        if(board[i] == board[rdx] || abs(board[i] - board[rdx]) == rdx - i) {
            return false;
        }
    }
    return true;
}

void dfs(int rdx) {
    if(rdx == N) {
        ans++;
        return;
    }
    for(int i = 0; i < N; i++) {
        board[rdx] = i;
        if(promising(rdx)) dfs(rdx + 1);
    }
}

int main()  
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    cin >> N;

    //SOLVE
    dfs(0);    

    //OUTPUT
    cout << ans;
    
}