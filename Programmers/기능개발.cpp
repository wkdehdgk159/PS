//기능개발 (Level 2, 큐)
//https://school.programmers.co.kr/learn/courses/30/lessons/42586

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> required_time;
    
    for(int i = 0; i < progresses.size(); i++) {
        int p = 100 - progresses[i];
        //맞아 떨어지면
        if(p % speeds[i] == 0) required_time.push_back(p / speeds[i]);
        else required_time.push_back(p / speeds[i] + 1);
    }

    for(int i = 0; i < required_time.size(); i++) {
        int cnt = 1;
        int idx = i;
        while((i != required_time.size()-1) && required_time[idx] >= required_time[i+1]) {
            cnt++;
            i++;
        }
        answer.push_back(cnt);
    }
    
    return answer;
}
/*
1. 100% 개발이 될 때까지 걸리는 일 수를 구한다.
2. 현재 기능이 걸리는 일 수보다 적게 걸리는 기능들을 쭉 배포한다.
*/