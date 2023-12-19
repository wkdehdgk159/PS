//게임 맵 최단거리 (Level 2, BFS)
//https://school.programmers.co.kr/learn/courses/30/lessons/1844

#include<vector>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

bool visited[100][100];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,-1,1};
int n, m;
vector<vector<int> > MAP;

int bfs() {

    int result = 50000;
    queue<pair<pair<int, int>, int> > q; //{{현재 좌표}, 지금까지 온 거리}

    q.push({{0,0}, 1});

    while(!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int c_len = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m || visited[nx][ny] || !MAP[nx][ny]) continue;

            visited[nx][ny] = true;
            if(nx == n - 1 && ny == m - 1) {
                result = c_len + 1;
                break;
            }
            q.push({{nx, ny}, c_len+1});
        }
    }
        return result;
}

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    
    MAP = maps;
    memset(visited, 0, sizeof(visited));
    n = maps.size();
    m = maps[0].size();

    //SOLVE
    answer = bfs();
    if(answer == 50000) answer = -1;
    
    return answer;
}
//단순 BFS