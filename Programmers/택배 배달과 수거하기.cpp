//택배 배달과 수거하기(Level 2, 그리디)
//https://school.programmers.co.kr/learn/courses/30/lessons/150369
#include <string>
#include <vector>
#include <stack>

using namespace std;

stack<pair<int, int> > ds; //deliveries 관리 스택
stack<pair<int, int> > ps; //pickup 관리 스택 {거리, 상자 개수} 형태로 push

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    
    //INPUT
    for(int i = 0; i < n; i++) {
        if(deliveries[i] != 0) {
            ds.push({i+1, deliveries[i]});
        }
        if(pickups[i] != 0) {
            ps.push({i+1, pickups[i]});
        }
    }

    //SOLVE
    
    //두 스택이 모두 빌때까지
    while(!(ds.empty() && ps.empty())) {
        //더 먼 거리 찾기
        int dd = 0, pd = 0;
        if(!ds.empty()) dd = ds.top().first;
        if(!ps.empty()) pd = ps.top().first;
        int target_distance = max(dd, pd);

        int dc = cap;
        int pc = cap;

        while(dc > 0 && !ds.empty()) {
            pair<int, int> curr_dh = ds.top();
            ds.pop();
            //현재 배달 용량보다 배달할 물량이 많다면 배달한 물량만큼 빼주고 다시 Push
            if(curr_dh.second > dc) {
                curr_dh.second -= dc;
                dc = 0;
                ds.push(curr_dh);
            } 
            //배달할 물량이 적거나 같다면 dc만 차감해준다.
            else {
                dc -= curr_dh.second;
            }
        }

        while(pc > 0 && !ps.empty()) {
            pair<int, int> curr_ph = ps.top();
            ps.pop();
            //현재 배달 용량보다 배달할 물량이 많다면 배달한 물량만큼 빼주고 다시 Push
            if(curr_ph.second > pc) {
                curr_ph.second -= pc;
                pc = 0;
                ps.push(curr_ph);
            } 
            //배달할 물량이 적거나 같다면 dc만 차감해준다.
            else {
                pc -= curr_ph.second;
            }
        }
        answer += 2 * target_distance;
    }
    
    return answer;
}

/*
1. 배달, 수거할 상자가 있는 가장 먼 집을 가야한다.
2. pair 형식 스택 두개 만들어서 cap개씩 빼주면서 관리해준다면?
*/