//프로세스 (Level 2, 구현, 큐)
//https://school.programmers.co.kr/learn/courses/30/lessons/42587
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    vector<vector<int> > procs(10);
    int cnt = 0;
    int max_p = 0;

    //SOLVE
    //priority 별 벡터에 location 정보들 넣기
    for(int i = 0; i < priorities.size(); i++) {
        procs[priorities[i]].push_back(i);
    }

    int former_location = -1;
    for(int i = 9; i >= 1; i--) {
        if(procs[i].size() == 0) continue;

        int std_l = 0;
        //현재 procs를 모두 순회하기 위해 가장 빠르게 실행되는 location index 찾기
        for(int j = 0; j < procs[i].size(); j++) {
            if(former_location < procs[i][j]) {
                std_l = j;
                break;
            }
        }

        int idx = std_l;
        //현재 procs를 순회하면서 같은 location이 있는지 확인
        do {
            cnt++;
            if(procs[i][idx] == location) {
                answer = cnt;
                break;
            }

            former_location = procs[i][idx];
            idx++;
            if(idx == procs[i].size()) idx = 0;
        }while(idx != std_l);

        if(answer != 0) break;
    }
    
    return answer;
}

/*
1. priority 별로 벡터를 만든다
2. 이전에 실행된 작업의 Location 기준으로 다음 priority 작업들 수행하기. 
3. 근데 큐쓰는 문제였네?
*/