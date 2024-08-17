#include <string>
#include <vector>

using namespace std;

vector<int> make_pulse(vector<int> sequence, int n) {
    
    for(int i = 0; i < sequence.size(); i++) {
        sequence[i] *= n;
        n *= -1;
    }
    
    return sequence;
}

long long solution(vector<int> sequence) {
    long long answer = -50000000000;
    
    //1로 시작하는 펄스, -1로 시작하는 펄스 만들기
    vector<int> pulse1 = make_pulse(sequence, 1);
    vector<int> pulse2 = make_pulse(sequence, -1);
    
    long long dp1[sequence.size()];
    long long dp2[sequence.size()];
    
    dp1[0] = pulse1[0];
    dp2[0] = pulse2[0];
    answer = max(dp1[0], dp2[0]);
    
    for(int i = 1; i < sequence.size(); i++) {
        dp1[i] = max(dp1[i-1] + (long long)pulse1[i], (long long)pulse1[i]);
        answer = max(answer, dp1[i]);
    }
    
    for(int i = 1; i < sequence.size(); i++) {
        dp2[i] = max(dp2[i-1] + (long long)pulse2[i], (long long)pulse2[i]);
        answer = max(answer, dp2[i]);
    }
    
    return answer;
}