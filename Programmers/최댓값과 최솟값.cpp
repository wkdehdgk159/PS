//최댓값과 최솟값 (Level 2, 문자열)
//https://school.programmers.co.kr/learn/courses/30/lessons/12939
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    int l1 = 0, l2;
    int maxn = -2000000000, minn = 2000000000;
    
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == ' ' || i == s.length()-1) {
            l2 = i-1;
            if(i == s.length()-1) l2 = i;
            int num = stoi(s.substr(l1, l2-l1+1));
            maxn = max(maxn, num);
            minn = min(minn, num);
            l1 = i + 1;
        }
    }
    
    answer = to_string(minn) + " " + to_string(maxn);
    
    return answer;
}