//https://www.acmicpc.net/problem/2933
//2933. 미네랄(Gold 2, BFS, 시뮬레이션)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

#define endl "\n"
#define INT_INF 2147483647
#define LL_INF 9223372036854775807
#define ll long long
using namespace std;

int R, C, T;
char board[101][101];
bool visited[101][101];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void print_map() {
    for(int i = R; i >= 1; i--) {
        for(int j = 1; j <= C; j++) {
            cout << board[i][j];
        }
        cout << endl;
    }
}

void bfs(int h, int l_or_r) {
    //타격점 찾기
    pair<int, int> hit_point = make_pair(0, 0);
    if(l_or_r == 0) {
        for(int i = 1; i <= C; i++) {
            if(board[h][i] == 'x') {
                hit_point.first = h;
                hit_point.second = i;
                break;
            }
        }
    }
    else {
        for(int i = C; i >= 1; i--) {
            if(board[h][i] == 'x') {
                hit_point.first = h;
                hit_point.second = i;
                break;
            }
        }
    }
    //타격되는 미네랄이 없다면 종료
    if(hit_point.first == 0) return;
    board[hit_point.first][hit_point.second] = '.';

    //타격된 영향으로 분리된 클러스터 찾기. BFS로 쭉 따라갔을 때 접지되는 부분이 없다면 분리된 클러스터이다
    int dir = 10;
    //분리된 미네랄들을 저장하기 위한 벡터
    vector<pair<int, int> > minerals;
    for(int i = 0; i < 4; i++) {
        int sflag = 0;
        int x = hit_point.first + dx[i];
        int y = hit_point.second + dy[i];
        if(x < 1 || y < 1 || x > R || y > C || board[x][y] == '.') continue;
        memset(visited, 0, sizeof(visited));
        queue<pair<int, int> > q;
        q.push(make_pair(x, y));
        minerals.push_back(make_pair(x, y));
        visited[x][y] = 1;
        int eflag = 0;

        while(!q.empty()) {
            int cx = q.front().first;
            int cy = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                if(nx < 1 || ny < 1 || nx > R || ny > C || visited[nx][ny] || board[nx][ny] == '.') continue;
                //만약 nx가 1이라면 높이 1에 닿는 미네랄이 있다는 것이므로 패스
                if(nx == 1) {
                    eflag = 1; break;
                }
                q.push(make_pair(nx, ny));
                minerals.push_back(make_pair(nx, ny));
                visited[nx][ny] = 1; 
            }
            if(eflag) break;
        }
        //큐를 다 썼는데도 eflag가 세워지지 않았다면 접지되지 않았다는 의미이므로 그 방향을 저장
        if(eflag == 0) {
            dir = i; break;
        }
        minerals.clear();
    }

    //타격은 있지만 분리된 클러스터가 없다는 의미이므로 종료
    if(dir == 10) {
        return;
    }

    //분리된 클러스터를 얼마나 내려야하는지 구해야 한다. 분리된 클러스터 내의 모든 미네랄을 돌면서
    //두칸 이상 떨어진 곳에 땅이나 미네랄이 있다면 그 최소 높이를 구해줌
    int min_h = 101;

    for(int i = 0; i < minerals.size(); i++) {
        int x = minerals[i].first;
        int y = minerals[i].second;
        int tmp = 1;
        while(1) {
            //클러스터가 땅에 닿는 경우
            if(x - tmp == 1) {
                min_h = (min_h > tmp) ? tmp : min_h;
                break;
            }
            //클러스터가 다른 클러스터의 미네랄을 만나는 경우
            else if(board[x - tmp - 1][y] == 'x') {
                int ef = 0;
                //다른 클러스터인지 검증해야함
                for(int j = 0; j < minerals.size(); j++) {
                    if(x-tmp-1 == minerals[j].first && y == minerals[j].second) {
                        ef = 1; break;
                    }
                }
                if(ef == 0) {
                    min_h = (min_h > tmp) ? tmp : min_h;
                    break;
                }
            }
            tmp++;
        }
    }

    //내릴 높이가 정해졌으니 원래 모든 미네랄 칸들을 0으로 만들어줌
    for(int i = 0; i < minerals.size(); i++) {
        board[minerals[i].first][minerals[i].second] = '.';
    }
    //내려간 칸만큼 미네랄 적용
    for(int i = 0; i < minerals.size(); i++) {
        board[minerals[i].first - min_h][minerals[i].second] = 'x';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    cin >> R >> C;
    for(int i = R; i >= 1; i--) {
        for(int j = 1; j <= C; j++) {
            cin >> board[i][j];
        }
    }
    cin >> T;

    //SOLVE
    int h;
    for(int i = 0; i < T; i++) {
        cin >> h;
        bfs(h, i % 2); //쏘는 높이, 어느 쪽에서 쏘는지(짝수가 왼쪽에서)
    }

    //OUTPUT
    print_map();
}
//구현이 무척 까다로웠던 문제