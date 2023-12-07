//수식 최대화 (Level 2, 구현)
//https://school.programmers.co.kr/learn/courses/30/lessons/67257

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(string expression) {
    
    //INPUT
    long long answer = 0;
    vector<char> buho_priority;
    vector<char> buho;
    vector<long long> cal;

    long long tmp = 0;
    for(int i = 0; i < expression.length(); i++) {
        char cchar = expression[i];
        //부호라면
        if('0' > cchar || cchar > '9') {
            cal.push_back(tmp);
            tmp = 0;
            buho.push_back(cchar);
        }

        //숫자라면
        else {
            tmp = tmp * 10 + cchar - '0';
        }

        if(i == expression.length() - 1) cal.push_back(tmp);
    }

    //SOLVE
    buho_priority = buho;

    //next_permutation 써주기 위해 미리 sort하고 중복제거
    sort(buho_priority.begin(), buho_priority.end());
    buho_priority.erase(unique(buho_priority.begin(),buho_priority.end()), buho_priority.end());

    do {
        vector<long long> tmp_cal = cal;
        vector<char> tmp_buho = buho;

        //계산할 부호 확정
        for(int i = 0; i < buho_priority.size(); i++) {
            char cur_buho = buho_priority[i];

            for(int j = 0; j < tmp_buho.size(); j++) {
                //해당하는 부호일 떄 계산하고 결과값 넣고 부호는 뺴주기
                if(tmp_buho[j] == cur_buho) {
                    long long sum;
                    if(cur_buho == '+') sum = tmp_cal[j] + tmp_cal[j+1];
                    else if(cur_buho == '-') sum = tmp_cal[j] - tmp_cal[j+1];
                    else sum = tmp_cal[j] * tmp_cal[j+1];

                    //연산에 쓰인 숫자 두개 뺴고 결과값 넣어주기
                    //부호는 빼기
                    tmp_cal.erase(tmp_cal.begin() + j);
                    tmp_cal.erase(tmp_cal.begin() + j);
                    tmp_cal.insert(tmp_cal.begin() + j, sum);
                    tmp_buho.erase(tmp_buho.begin() + j);

                    //다음 계산할 부호도 앞과 동일하다면 j--
                    if(tmp_buho[j] == cur_buho) j--;
                }
            }
        }

        //나온 결과값이 최대인지 확인
        answer = max(answer, abs(tmp_cal[0]));

        //다른 부호 조합
    }while(next_permutation(buho_priority.begin(), buho_priority.end()));
    
    return answer;
}
/*
1. next_permutation 돌면서 부호조합
*/