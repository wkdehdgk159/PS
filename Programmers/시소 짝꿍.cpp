//시소 짝꿍 (Level 2, 구현)
//https://school.programmers.co.kr/learn/courses/30/lessons/152996

#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    
    map<int, long long> wcm;
    vector<int> uwv;

    //SOLVE
    sort(weights.begin(), weights.end());
    int tmp = 1;
    
    //같은 몸무게 세고 중복제거 + 맵 만들기
    for(int i = 1; i < weights.size(); i++) {
        if(weights[i-1] == weights[i]) {
            tmp++;
        }
        else {
            uwv.push_back(weights[i-1]);
            wcm[weights[i-1]] = tmp;
            tmp = 1;
        }
        if(i == weights.size() - 1) {
            uwv.push_back(weights[i]);
            wcm[weights[i]] = tmp;
        }
    }

    //같은 몸무게에서 2명을 고르는 경우
    for(int i = 0; i < uwv.size(); i++) {
        long long cnt = wcm[uwv[i]];
        answer += cnt * (cnt-1) / 2;
    }

    
    //다른 몸무게와 매칭되는 경우
    for(int i = 0; i < uwv.size(); i++) {
        for(int m = 2; m <= 4; m++) {
            int cw = uwv[i] * m;
            for(int j = i + 1; j < uwv.size(); j++) {
                for(int m2 = 2; m2 <= 4; m2++) {
                    int dw = uwv[j] * m2;
                    if(dw == cw) {
                        answer += wcm[uwv[i]] * wcm[uwv[j]];
                    }
                }
            }
        }
    }
    
    return answer;
}
/*
1. sort하고 맵에 몸무게 개수담고 중복 제거
2. for문 돌면서 매치되는 것 개수끼리 곱한 경우의 수 + 같은 몸무게에서 2개 고르는 경우의 수
*/