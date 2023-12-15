//n^2 배열 자르기 (Level 2, 수학)
//https://school.programmers.co.kr/learn/courses/30/lessons/87390

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    int cur_r, cur_c, result;
    for(long long i = left; i <= right; i++) {
        cur_r = i / n + 1;
        cur_c = i % n + 1;

        //현재 행이 열보다 뒤에 있다면
        if(cur_r <= cur_c) result = cur_c;
        else {
            result = cur_r;
        }
        answer.push_back(result);
    }
    
    return answer;
}
/*
1. left, right가 몇행 몇열인지 구하고 열 단위로 넣어줄 벡터구해서 insert -> 메모리 초과
2. 좌표 하나하나당 행이 앞서는 지 열이 앞서는 지에 따라 숫자 확정 지어주기. -> good
*/