#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<vector<string>> tickets_;
vector<string> answer;

//(현재 위치, 경로 저장하는 벡터, 사용여부 저장하는 배열, 사용된 티켓 수)
void dfs(string curr, vector<string> rv, vector<bool> used, int cnt) {
    
    //티켓 다 사용했으면
    if(tickets_.size() == cnt) {
        rv.push_back(curr);
        answer = rv;
        return;
    }
    
    for(int i = 0; i < tickets_.size(); i++) {
        if(tickets_[i][0] != curr || used[i]) continue;
        
        string nc = tickets_[i][1];
        rv.push_back(curr);
        used[i] = true;
        
        if(answer.size() > 0) break;
        
        dfs(nc, rv, used, cnt + 1);
        
        //백트래킹을 위해 초기화
        rv.pop_back();
        used[i] = false;
    }
    
    
}

vector<string> solution(vector<vector<string>> tickets) {
    
    tickets_ = tickets;
    sort(tickets_.begin(), tickets_.end());
    
    for(int i = 0; i < tickets_.size(); i++) {
        cout << tickets_[i][0] << " " << tickets_[i][1] << "    ";
    }
    
    vector<string> rv;
    vector<bool> vv(tickets_.size(), false);
    dfs("ICN", rv, vv, 0);
    
    return answer;
}

//unordered_map<string, vector<string>> -> 너무 복잡한데?
//DFS는 맞는 것 같은데 중복처리를 어떻게 막을까? visited는 중복되니까 ticket 사용여부로 막자
//ticket 정렬해서 알파벳 순 맞춰주고 벡터에 넣고 백트래킹 하면서 dfs 진행한다.
//근데 현재 위치가 0번 원소인 애들 다 체크한다고 치면 시간복잡도가 어떻게 되는 거지? 