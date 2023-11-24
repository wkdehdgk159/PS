//괄호 회전하기 (Level 2, 스택)
//https://school.programmers.co.kr/learn/courses/30/lessons/76502

#include <string>
#include <vector>
#include <stack>

using namespace std;

char paren[2001];

int solution(string s) {
    int answer = 0;
    for(int i = 0; i < s.length(); i++) {
        paren[i+1] = s[i];
    }
    int start_idx = 1, end_idx = s.length();
    

    //SOLVE
    while(start_idx <= s.length()) {
        int a = 0, b = 0, c = 0;
        stack<char> st;

        //올바른 괄호 문자열인지 검증
        for(int i = start_idx; i <= end_idx; i++) {
            if(st.empty() && (paren[i] == ']' || paren[i] == '}' || paren[i] == ')')) break;
            if(paren[i] == '[' || paren[i] =='{' || paren[i] == '(') {
                st.push(paren[i]);
            }
            else if((paren[i] == ']' && st.top() == '[')
            || (paren[i] == '}' && st.top() == '{')
            || (paren[i] == ')' && st.top() == '(')) st.pop();
            else break;

            //끝까지 왔으면서 stack이 비었다면 answer++
            if(i == end_idx && st.empty()) answer++;
        }

        //한번 회전 시켜주고 idx 수정
        paren[end_idx + 1] = paren[start_idx];
        start_idx++; end_idx++;
    }
    
    return answer;
}