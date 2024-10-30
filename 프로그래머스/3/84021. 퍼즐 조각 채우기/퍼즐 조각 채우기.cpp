#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int answer = 0;
vector<vector<pair<int, int>>> blanks;
vector<vector<pair<int, int>>> origin_puzzles;
vector<vector<vector<pair<int, int>>>> puzzles;
bool visited[50][50];
bool used[2500];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

//빈칸과 퍼즐을 좌표화시켜주는 bfs. option=0이면 blank, 1이면 puzzles
void bfs(vector<vector<int>> board, int option) {
    
    //방문기록 초기화
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board.size(); j++) {
            visited[i][j] = false;
        }
    }
    
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board.size(); j++) {
            //방문한 곳이나 원하는 칸이 아니면 skip
            if(visited[i][j] || board[i][j] != option) continue;
            
            queue<pair<int, int>> q;
            vector<pair<int, int>> tmp;
            
            q.push({i, j});
            tmp.push_back({i, j});
            visited[i][j] = true;
            
            while(!q.empty()) {
                
                int cx = q.front().first;
                int cy = q.front().second;
                q.pop();
                
                for(int i = 0; i < 4; i++) {
                    int nx = cx + dx[i];
                    int ny = cy + dy[i];
                    
                    if(nx < 0 || ny < 0 || nx >= board.size() || ny >= board.size() || visited[nx][ny] || board[nx][ny] != option) continue;
                    visited[nx][ny] = true;
                    tmp.push_back({nx, ny});
                    q.push({nx, ny});
                }
            }
            
            if(option == 0) blanks.push_back(tmp);
            else origin_puzzles.push_back(tmp);
        }
    }
}

//0,0 기준으로 표준화
void normalize(vector<pair<int, int>> &v) {
    
    int minx = 50, miny = 50;
    for(int i = 0; i < v.size(); i++) {
        minx = min(minx, v[i].first);
        miny = min(miny, v[i].second);
    }
    for(int i = 0; i < v.size(); i++) {
            v[i].first -= minx;
            v[i].second -= miny;
    }
}

//90도 회전시키면서 3개 더 추가하여 반환
vector<vector<pair<int, int>>> rotate(vector<pair<int, int>> v) {
    
    vector<vector<pair<int, int>>> rotated;
    
    rotated.push_back(v);
    
    for(int i = 0; i < 3; i++) {
        vector<pair<int, int>> tmp;
        for(int j = 0; j < v.size(); j++) {
            int nx = -v[j].second;
            int ny = v[j].first;
            tmp.push_back({nx, ny});
        }
        v = tmp;
        normalize(tmp);
        rotated.push_back(tmp);
    }
    
    return rotated;   
}

bool match(vector<pair<int, int>> a, vector<pair<int, int>> b) {
    
    if(a.size() != b.size()) return false;
    for(int i = 0; i < a.size(); i++) {
        if(a[i].first != b[i].first || a[i].second != b[i].second) return false;
    }
    return true;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    
    //빈칸 좌표화해서 blanks 벡터에 넣기
    bfs(game_board, 0);
    
    //퍼즐 조각 좌표화해서 origin_puzzles 벡터에 넣기
    bfs(table, 1);
    
    //모든 좌표들 표준화
    for(int i = 0; i < blanks.size(); i++) {
        normalize(blanks[i]);
    }
    for(int i = 0; i < origin_puzzles.size(); i++) {
        normalize(origin_puzzles[i]);
    }
    
    //puzzles 벡터에 회전한 케이스도 추가하기
    for(int i = 0; i < origin_puzzles.size(); i++) {
        puzzles.push_back(rotate(origin_puzzles[i]));
    }
    
    //비교 용이하게 좌표들 정렬
    for(int i = 0; i < blanks.size(); i++) {
        sort(blanks[i].begin(), blanks[i].end());
    }
    
    for(int i = 0; i < puzzles.size(); i++) {
        for(int j = 0; j < puzzles[i].size(); j++) {
            sort(puzzles[i][j].begin(), puzzles[i][j].end());
        }
    }
    
    //blanks와 puzzles 비교해서 칸 채우기
    for(int i = 0; i < blanks.size(); i++) {
        //이제 이 빈 조각과 맞는 퍼즐 조각을 찾아라
        vector<pair<int, int>> blank = blanks[i];
        //매치된 조각 찾았을 때 탈출을 위해
        bool skip_flag = false;
        for(int j = 0; j < puzzles.size(); j++) {
            //사용한 조각이면 skip
            if(used[j]) continue;
            for(int k = 0; k < puzzles[j].size(); k++) {
                //딱 맞아들어가면 정답 더하고 사용처리
                if(match(blank, puzzles[j][k])) {
                    answer+= blank.size();
                    used[j] = true;
                    skip_flag = true;
                    cout << j << " " << answer << endl;
                    break;
                }
            }
            if(skip_flag) break;
        }
    }
    
    return answer;
}

//같은 모양인지 판별을 어떻게? -> 가장 왼쪽 위칸을 (0,0) 으로 잡아 표준화 시켜준다. blank와 puzzle 벡터에 넣어줌
//회전은 어떻게? -> x = -y, y = x 회전 행렬 이용해서 총 4개를 puzzle 벡터에 넣어주자.
//used 배열하나 만들어서 사용여부 관리.
//좌표 하나하나 다 일치하는지 확인하면 힘드니 애초에 정렬해서 좌표들 넣자.