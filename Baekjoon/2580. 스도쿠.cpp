//https://www.acmicpc.net/problem/2580
//2580. 스도쿠(Gold 4, 백트래킹)

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
int board[9][9];
int e_flag = 0;
int n_point;
vector<pair<int, int> > point; 

bool promising(int r, int c, int n) {//(r, c)에 n을 넣었을 때 적합한지
    //행열 체크
    for(int i = 0; i < 9; i++) {
        if(i == c) continue;
        if(board[r][i] == n) return false;
    }
    for(int i = 0; i < 9; i++) {
        if(i == r) continue;
        if(board[i][c] == n) return false;
    }
    //3x3 체크
    int sr, sc;
    sr = r / 3 * 3;
    sc = c / 3 * 3;
    for(int i = sr; i < sr + 3; i++) {
        for(int j = sc; j < sc + 3; j++) {
            if(i == r && j == c) continue;
            if(board[i][j] == n) return false;
        }
    }
    return true;
}

void dfs(int idx) {
    if(idx == n_point) {
        e_flag = 1;
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        return;
    }

    int r = point[idx].first;
    int c = point[idx].second;

    for(int i = 1; i <= 9; i++) {
        board[r][c] = i;
        if(promising(r, c, i)) {
            dfs(idx + 1);
        }
        if(e_flag) return;
        board[r][c] = 0;
    }
}

int main()  
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cin >> board[i][j];
            if(board[i][j] == 0) point.push_back(make_pair(i, j));
        }
    }

    //SOLVE
    n_point = point.size();
    // cout << promising(0, 0, 2);
    dfs(0);   

    //OUTPUT
    
}
//백트래킹 완전탐색 문제였다.
//배운 점은 답이 여러개가 나올 수 있을 때 ans배열을 따로 선언하여 저장하기보다
//외부 함수라도 플래그를 사용하여 한번만 출력하고 끝내면 시간단축이 가능