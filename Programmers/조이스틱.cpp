//조이스틱 (Level 2, 구현)
//https://school.programmers.co.kr/learn/courses/30/lessons/42860

#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0;
    
    //초기값은 길이-1
    int dist = name.length() - 1;

    //가장 긴 연속 A만큼은 커서를 옮길 필요가 없으므로 미리 처리
    for(int i = 0; i < name.length(); i++) {
        int tmp = 9999999;
        if(name[i] == 'A') {
            int start_idx = i;
            tmp = 0;
            while(i < name.length() && name[i+1] == 'A') {
                i++;
            }
            int end_idx = i;

            //A가지 않으므로써 구해지는 거리
            //우측으로 이동해야하는 거리
            int right = start_idx - 1;
            if(right < 0) right = 0;
            int left = name.length() - end_idx - 1;  
            if(right >= left) tmp = right + left * 2;
            else tmp = left + right * 2;
        }
        dist = min(dist, tmp);
    }

    //남은 알파벳들은 A와의 위치 차이만큼 더해주기
    for(int i = 0; i < name.length(); i++) {
        int tmp = name[i] - 'A';
        tmp = min(26-tmp, tmp);
        answer += tmp;
    }
    answer += dist;
    
    return answer;
}

/*
1. 원래는 다 가긴 해야하는데. A 위치가 좋거나 연속성이 좋아서 가지 않는 게 이득인 경우가 있음.
2. 1을 고려하여 커서를 움직여야할 최소 횟수를 구하고.
3. 나머지 친구들은 A와 비교하여 각각 횟수를 더해주면 됨.
4. 2 + 3 이 정답.
*/