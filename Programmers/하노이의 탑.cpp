//하노이의 탑 (Level 2, 재귀)
//https://school.programmers.co.kr/learn/courses/30/lessons/12946

#include <string>
#include <vector>

using namespace std;

vector<vector<int>> answer;
void hanoi(int num, int start, int dest, int rest) {
    if(num == 1) {
        answer.push_back({start, dest});
        return;
    }
    
    //가장 큰 원판을 제외한 나머지 원판들을 목적지가 아닌 다른 기둥에 둠
    hanoi(num-1, start, rest, dest);
    
    //가장 큰 원판을 목적지 아래에 둠
    hanoi(1, start, dest, rest);

    //남은 원판들을 가장 큰 원판 위에 둠
    hanoi(num-1, rest, dest, start);
}

vector<vector<int>> solution(int n) {
    hanoi(n, 1, 3, 2);
    return answer;
}

/*
1. 가장 큰 원판을 목적지에 두기 위해 나머지 원판들을 남는 기둥에 세운다.
2. 가장 큰 원판을 목적지에 둔다.
3. 남은 원판들을 목적지에 둔다.
*/