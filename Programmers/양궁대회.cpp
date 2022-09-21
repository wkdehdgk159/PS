//https://school.programmers.co.kr/learn/courses/30/lessons/92342
//양궁대회 (Level 2, 완전탐색 DFS)

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> answer(1, -1);
int max_diff = 0;

void cal(vector<int> rion, vector<int> apeach) {
    int r_score = 0, a_score = 0;
    
    for(int i = 0; i < 11; i++) {
        if(rion[i] > apeach[i]) r_score += 10 - i;
        else if(apeach[i] > 0) a_score += 10 - i;
    }
    
    int diff = r_score - a_score;
    if(max_diff <= diff && diff > 0) {
        //최대 차이와 현 차이가 같으면 낮은 명중이 더 많은 지 확인
        if(diff == max_diff) {
            for(int i = 10; i >= 0; i--) {
                if(rion[i] > answer[i]) break;
                if(answer[i] > rion[i]) return;
            }       
        }
        max_diff = diff;
        answer = rion;
        return;
    }
    return;
}

void dfs(int idx, int arrows, vector<int> rion, vector<int> apeach) {
    //마지막까지 왔다면 남은 화살은 다 0점에 쏘고 계산
    if(idx == 10 || arrows == 0) {
        rion[10] += arrows;
        cal(rion, apeach);
        return;
    }   
    
    //남은 화살의 개수가 해당 idx의 어피치보다 많이 쏠 수 있다면 하나만 더 쏜 후 다음 과녁으로
    if(arrows > apeach[idx]) {
        rion[idx] += apeach[idx] + 1;
        dfs(idx + 1, arrows - apeach[idx] - 1, rion, apeach);
        rion[idx] -= apeach[idx] + 1;
    }
    dfs(idx + 1, arrows, rion, apeach);
}

vector<int> solution(int n, vector<int> info) {
    vector<int> rion(11, 0);
    vector<int> apeach(11, 0);
    apeach = info;
    
    dfs(0, n, rion, apeach);
    
    return answer;
}
//이게 레벨2? 라는 생각이 드는 문제였다.