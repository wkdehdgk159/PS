//과제 진행하기 (Level 2, 스택)
//https://school.programmers.co.kr/learn/courses/30/lessons/176962
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

bool compare(vector<string> a, vector<string> b) {
    return stoi(a[1]) < stoi(b[1]);
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    
    //시간 문자열 분 단위로 통합
    for(int i = 0; i < plans.size(); i++) {
        string t = plans[i][1];
        plans[i][1] = to_string(stoi(t.substr(0,2)) * 60 + stoi(t.substr(3,2)));
    }
    //시간 오름차순으로 정렬
    sort(plans.begin(), plans.end(), compare);

    //스택 <과제, 남은 시간>
    stack<pair<string, int> > st;

    int cur_idx = 0;

    //마지막 과제 전까지
    for(int i = 0; i < plans.size(); i++) {
        if(!st.empty()) {
            int remain_time = stoi(plans[i][1]) - stoi(plans[i-1][1]);
            while(!st.empty() && remain_time > 0) {
                //시간을 다 써도 못 끝내는 경우
                if(st.top().second > remain_time) {
                    st.top().second -= remain_time;
                    remain_time = 0;
                }
                //시간이 딱 맞거나 시간이 남는 경우
                else {
                    remain_time -= st.top().second;
                    answer.push_back(st.top().first);
                    st.pop();
                }
            }
        }
        st.push({plans[i][0], stoi(plans[i][2])});
    }
    
    //남은 친구들 순서대로 뺴주기
    while(!st.empty()) {
        answer.push_back(st.top().first);
        st.pop();
    }
    
    return answer;
}

/*
1. 너무나 스택 문제. 시간 오름차순으로 정렬하고 스택 넣다가
2. 시간 다 사용할 때 까지 pop하면서 처리
*/