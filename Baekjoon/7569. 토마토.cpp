//https://www.acmicpc.net/problem/7569
//7569. 토마토(Gold 5, BFS)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

#define endl "\n"
#define INT_INF 2147483647
#define LL_INF 9223372036854775807
#define ll long long

using namespace std;

int N, M, H, ans = 0, fc = 0;
int box[100][100][100];//입력 편의상 (z, y, x)로
queue<pair<pair<int, int>, int> > q;//익은 토마토 좌표
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    cin >> M >> N >> H;
    for(int i = 0; i < H; i++) { 
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < M; k++) {
                cin >> box[i][j][k];
                //익어야할 토마토 개수 세기
                if(box[i][j][k] == 0) fc++;
                if(box[i][j][k] == 1) q.push(make_pair(make_pair(i,j), k));
            }
        }
    } 

    // SOLVE
    //익어야할 토마토가 없으면 0 출력 후 종료
    if(fc == 0) {
        cout << 0;
        return 0;
    }

    while(true) {
        int c = q.size();
        int tmp = fc;
        ans++;
        for(int i = 0; i < c; i++) {
            int z = q.front().first.first;
            int y = q.front().first.second;
            int x = q.front().second;
            q.pop();

            for(int j = 0; j < 6; j++) {
                int nx = x + dx[j];
                int ny = y + dy[j];
                int nz = z + dz[j];
                if(nx < 0 || ny < 0 || nz < 0 || nx >= M || ny >= N || nz >= H) continue;
                if(box[nz][ny][nx] == 0) {
                    box[nz][ny][nx] = 1;
                    fc--;
                    q.push(make_pair(make_pair(nz,ny), nx));
                }
            }
        }
        //토마토를 모두 익혔다는 의미
        if(fc == 0) {
            cout << ans;
            return 0;
        }
        //이전 주기와 비교했을 때 익은 토마토 개수의 차이가 없고 0이 아니라면 토마토가 모두 익지 못하는 상황
        else if(fc == tmp) {
            cout << -1;
            return 0;
        }
    }

    //OUTPUT
    // cout << ans;
}
//3차원 좌표 입력이 조금 헷갈렸던 문제