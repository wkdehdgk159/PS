//큰 수 만들기 (Level 2, 그리디)
//https://school.programmers.co.kr/learn/courses/30/lessons/42883

#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    //SOLVE
    for(int i = 0; i < number.length()-1; i++) {

        if(number[i] >= number[i+1]) continue;

        //뒤 친구가 더 크다면 뺴는게 이득
        else if(number[i] < number[i+1]) {

            number = number.substr(0, i) + number.substr(i + 1,  number.length() - i - 1);
            
            //다시 앞에서 처음부터 보면 시간초과
            i = (i==0) ? -1 : i-2;
            k--;
        }

        if(k == 0) break;
    }

    //k가 남아있다면 뒤에서부터 뺴주기
    if(k) number = number.substr(0, number.length() - k);
    
    answer = number;
    
    return answer;
}
/*
뒤 숫자와 비교하여 빼주는 식으로 진행하였는데 한 테케에서 7초가 걸림
스택을 이용하거나 다른사람의 풀이 1번 넘 좋았는데 이건 비현실적..
*/