//빛의 경로 사이클 (Level 2, 구현)
//https://school.programmers.co.kr/learn/courses/30/lessons/86052

#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int r,c;
vector<string> grid1;
bool visited[501][501][4];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};

int drift(char g, int d) {
    if(g == 'L') {
        if(d == 0) return 3;
        if(d == 1) return 2;
        if(d == 2) return 0;
        if(d == 3) return 1;
    }
    else if(g == 'R') {
        if(d == 0) return 2;
        if(d == 1) return 3;
        if(d == 2) return 1;
        if(d == 3) return 0;
    } 
    else {
        return d;
    }
    return 0;
}

int cal(int cr, int cc, int k, int len) {

    if(visited[cr][cc][k]) return len;
    //방문표시하고
    visited[cr][cc][k] = true;

    int x = cr, y = cc, dir = k;
    dir = drift((char) grid1[x][y], dir);
    int nx = x + dx[dir];
    int ny = y + dy[dir];

    if(nx == r) nx = 0;
    else if(nx < 0 ) nx = r - 1;
    if(ny == c) ny = 0;
    if(ny < 0) ny = c - 1;

    return cal(nx, ny, dir, len + 1);
}

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    
    grid1 = grid;
    r = grid.size(), c = grid[0].length();
    memset(visited, 0, sizeof(visited));
    
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            for(int k = 0; k < 4; k++) {
                int result = cal(i, j, k, 0);
                if(result > 0) answer.push_back(result);
            }
        }
    } 

    sort(answer.begin(), answer.end());
    
    return answer;
}

/*
1. 중복 일단 생각하지 말고. 각각의 점 에서 쏜 다음 다시 본인 점으로 오면 길이 저장.
2. 근데 중복을 생각해야지? visited[500][500][4]로 체크
*/