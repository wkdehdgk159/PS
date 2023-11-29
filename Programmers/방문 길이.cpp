//방문 길이 (Level 2, 구현)
//https://school.programmers.co.kr/learn/courses/30/lessons/49994
#include <string>
#include <cstring>
using namespace std;

int solution(string dirs) {
    
    int answer = 0;
    
    //INPUT
    
    //(0,0) ~ (20,20) 원점은 (10,10)
    bool visited[21][21];
    pair<int, int> cur_loc = {10, 10};
    memset(visited, 0, sizeof(visited));
    
    //SOLVE
    for(int i = 0; i < dirs.length(); i++) {
        char order = dirs[i];

        if(order == 'U') {
            if(cur_loc.second + 2 > 20) continue;
            visited[cur_loc.first][cur_loc.second + 1] = true;
            cur_loc = {cur_loc.first, cur_loc.second + 2};
        } else if(order == 'D') {
            if(cur_loc.second - 2 < 0) continue;
            visited[cur_loc.first][cur_loc.second - 1] = true;
            cur_loc = {cur_loc.first, cur_loc.second - 2};
        } else if(order == 'R') {
            if(cur_loc.first + 2 > 20) continue;
            visited[cur_loc.first + 1][cur_loc.second] = true;
            cur_loc = {cur_loc.first + 2, cur_loc.second};
        } else {
            if(cur_loc.first - 2 < 0) continue;
            visited[cur_loc.first - 1][cur_loc.second] = true;
            cur_loc = {cur_loc.first - 2, cur_loc.second};
        }
    }
    
    for(int i = 0; i < 21; i++) {
        for(int j = 0; j < 21; j++) {
            if((i % 2 == 1 || j % 2 == 1) && visited[i][j]) {
                answer++;
            }
        }
    }
    
    return answer;
}
/*
1. 배열을 10, 10으로 친 다음. 한 칸을 걷는게 아니라 두 칸을 간다고 가정함.
2. 예를 들어 원점에서 U를 입력하면 (0,1)이 아니라 (0,2)로 간 것임.
3. 그럼 여기서 (0,1) 이 새로운 길을 걸었다고 말할 수 있으므로(20x20으로 쳤을때)
4. 명령이 끝나고 나서 홀수를 포함한 좌표들을 모두 체크.
*/