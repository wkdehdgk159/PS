//https://school.programmers.co.kr/learn/courses/30/lessons/118668
//코딩 테스트 공부 (Level 3, DP)

#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = 0;
    
    int dp[181][181]; //dp[i][j]는 알고력 i와 코딩력 j를 얻는데 필요한 시간
    for(int i = 0; i < 181; i++) {
        for(int j = 0; j < 181; j++) {
            dp[i][j] = 400;
        }
    }
    for(int i = 0; i < alp + 1; i++) {
        for(int j = 0; j < cop + 1; j++) {
            dp[i][j] = 0;
        }
    }
    // memset(dp, 400, sizeof(dp)); 이거 왜 안되는 걸까 구글링해도 안나옴
    int max_alp = -1, max_cop = -1; 
    
    //최종적으로 얻어야할 알고력, 코딩력 구하기
    for(int i = 0; i < problems.size(); i++) {
        if(problems[i][0] > max_alp) max_alp = problems[i][0];
        if(problems[i][1] > max_cop) max_cop = problems[i][1];
    }
    
    //***** 처음에 주어진 alp와 cop가 충분히 커서 이미 모든 문제를 풀 수도 있다. alp는 충분히 크고 cop은 학습이 필요할 때를 가정하면 alp를 필요한 max_alp로 낮춰주어 루프문을 돌 수 있게 만들어 준다.
    alp = min(alp, max_alp);
    cop = min(cop, max_cop);
    dp[alp][cop] = 0;
    
    for(int i = alp; i <= max_alp; i++) {
        for(int j = cop; j <= max_cop; j++) {
            if(i + 1 <= max_alp) dp[i+1][j] = min(dp[i+1][j], dp[i][j] + 1);
            if(j + 1 <= max_cop) dp[i][j+1] = min(dp[i][j+1], dp[i][j] + 1);
            
            for(int p = 0; p < problems.size(); p++) {    
                int alp_req = problems[p][0];
                int cop_req = problems[p][1];
                int alp_rwd = problems[p][2];
                int cop_rwd = problems[p][3];
                int cost = problems[p][4];
                int tmp_alp = i + alp_rwd;
                int tmp_cop = j + cop_rwd;
                
                if(alp_req <= i && cop_req <= j) {
                    //***** 문제를 풀었을 때 max_alp와 max_cop를 넘어서는 경우도 조건에 만족하니 갱신해준다.
                    tmp_alp = min(tmp_alp, max_alp);
                    tmp_cop = min(tmp_cop, max_cop);
                    dp[tmp_alp][tmp_cop] = min(dp[tmp_alp][tmp_cop], dp[i][j] + cost);
                }
            }
        }
    }
    
    answer = dp[max_alp][max_cop];
    return answer;
}

//***** 표시된 부분때문에 애를 먹었던 문제 DP 식까지는 쉬웠으나 엣지 케이스들을 잘 생각하자