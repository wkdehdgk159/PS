//의상 (Level 2, 해시)
//https://school.programmers.co.kr/learn/courses/30/lessons/42578
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    map<string, int> m;
    map<string, int>::iterator iter;
    vector<int> cv;
    vector<int> pv;
    int answer = 1;

    //SOLVE
    for(int i = 0; i < clothes.size(); i++) {
        string curr_cloth_type = clothes[i][1];
        if(m.count(curr_cloth_type) == 0) {
            m.insert(make_pair(curr_cloth_type, 1));
        } else {
            m[curr_cloth_type]++;
        }
    }
    
    for(iter = m.begin(); iter!= m.end(); iter++) {
        answer *= iter->second + 1;
    }

    if(cv.size() == 1) return cv[0];
    answer -= 1;
    
    return answer;
}
/*
옷 각각 종류의 개수 + 1을 곱한다.(안 입는 경우의 수를 고려하여 + 1)
모두 안 입는 경우의 수 1을 빼준다.
*/