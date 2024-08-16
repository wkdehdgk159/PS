#include <string>
#include <vector>

using namespace std;

vector<int> answer(1, -1);
int max_diff = 0;
vector<int> apeach(11, 0);

//점수 차이 계산함수
void cal(vector<int> rion) {
    
    int r_score = 0, a_score = 0;
    
    //총점 계산
    for(int i = 0; i < 11; i++) {
        if(apeach[i] < rion[i]) r_score += 10 - i;
        else if(apeach[i] > 0) a_score += 10 - i;
    }
    
    //현재까지 최고의 결과인가?
    int diff = r_score - a_score;
    // if(diff == 0) return;
    // if(max_diff <= diff) {
    //     max_diff = diff;
    //     answer = rion;
    // }
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

//dfs - 라이언 배열, idx, 남은 화살 수 
void dfs(vector<int> rion, int idx, int arrows) {
    
    //화살이 없거나 마지막 0점까지 오면 종료
    if(idx == 10 || arrows == 0) {
        rion[10] += arrows;
        cal(rion);
        return;
    }
    
    //남은 화살의 개수가 해당 idx의 어피치보다 하나 더 쏠 수 있다면 체킹
    if(arrows > apeach[idx]) {
        rion[idx] = apeach[idx] + 1;
        dfs(rion, idx + 1, arrows - rion[idx]);
        rion[idx] = 0;
    }
    dfs(rion, idx + 1, arrows);
}

vector<int> solution(int n, vector<int> info) {
    
    vector<int> rion(11, 0);
    apeach = info;
    
    dfs(rion, 0, n);
    return answer;
}