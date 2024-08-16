#include <string>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;
int map[1000][1000];
int acu_sum[1001][1001];

void act(int type, int r1, int c1, int r2, int c2, int degree) {
    int d = degree;
    if(type == 1) d = -d;
    acu_sum[r1][c1] += d;
    acu_sum[r2+1][c1] -= d;
    acu_sum[r1][c2+1] -= d;
    acu_sum[r2+1][c2+1] += d;
}

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    memset(map, 0, sizeof(map));
    memset(acu_sum, 0, sizeof(acu_sum));
    int n = board.size();
    int m = board[0].size();
    for(int i = 0; i < n; i++) {
        vector<int>::iterator it = board[i].begin();
        for(int j = 0; j < m; j++) {
            map[i][j] = *it;
            it++;
        }
    }
    
    int type, r1, c1, r2, c2, degree;
    for(int i = 0; i < skill.size(); i++) {
        type = skill[i][0], r1 = skill[i][1], c1 = skill[i][2], r2 = skill[i][3], c2 = skill[i][4], degree = skill[i][5];
        act(type, r1, c1, r2, c2, degree);
    }
    
    //왼쪽에서 오른쪽으로 누적합
    for(int i = 0; i < n; i++) {
        for(int j = 1; j < m; j++) {
            acu_sum[i][j] += acu_sum[i][j-1];
        }
    }
    //위에서 아래
    for(int i = 0; i < m; i++) {
        for(int j = 1; j < n; j++) {
            acu_sum[j][i] += acu_sum[j-1][i];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(map[i][j] + acu_sum[i][j] > 0) answer++;
        }
    }
    
    return answer;
}