//올바른 괄호 (Level 2, 큐)
//https://school.programmers.co.kr/learn/courses/30/lessons/12909

#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    //INPUT
    stack<char> st;
    for(int i = 0; i < s.length(); i++) st.push(s[i]);

    //SOLVE
    int l = 0, r = 0;
    while(!st.empty()) {
        if(st.top() == '(') l++;
        else r++;
        st.pop();
        //매치되는 짝이 나왔으므로 초기화
        if(l == r) {
            l = 0; r = 0;
        }
        //뒤에서부터 보는데 왼쪽 괄호가 더 많아지면 false
        else if(l > r) return false;
    }

    //스택을 다 비웠는데도 l과 r이 남아있다면 짝이 안 맞는다.
    if(l > 0 || r > 0) answer = false;

    return answer;
}
/*
스택에 다 때려박고 뒤에서부터 짝 맞는지 확인
왼쪽 괄호가 더 많아지는 상황 or 끝까지 다 봤는데 개수가 다른 상황 이면 false
왼쪽, 오른쪽 개수가 일치하는 상황에는 초기화
*/