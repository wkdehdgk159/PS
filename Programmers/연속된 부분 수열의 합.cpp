//연속된 부분 수열의 합 (Level 2, 슬라이딩 윈도우)
//https://school.programmers.co.kr/learn/courses/30/lessons/178870
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer(2);
    
    int start = 0, end = 0;
    int sum = sequence[start];
    int min_len = 1000001;

    while(start <= end && end < sequence.size()) {

        if(sum < k) {
            end++;
            sum += sequence[end];
        }
        else if(sum > k) {
            sum -= sequence[start];
            start++;
        }
        else {
            if(end - start + 1 < min_len) {
                min_len = end - start + 1;
                answer[0] = start;
                answer[1] = end;
            }
            
            sum -= sequence[start];
            start++;
        }
    }

    
    return answer;
}
/*
1. start end 두고 슬라이딩 머시기로 풀자.
*/