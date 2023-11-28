//압축 (Level 2, 해시, 문자열)
//https://school.programmers.co.kr/learn/courses/30/lessons/17684
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    
    map<string, int> dmap;
    string s;
    for(int i = 0; i < 26; i++) {
        string s = string(1, i+'A');
        dmap.insert({s, i+1});
    }
    
    int start_idx = 0, end_idx = 0, map_cnt = 26;
    while(end_idx < msg.length()) {
        while(end_idx != msg.length()) {
            //구간에 해당하는 map이 있는지 확인
            string tmp_s = msg.substr(start_idx, end_idx - start_idx + 1);
            if(dmap.find(tmp_s) != dmap.end()) {
                end_idx++;
            } else break;
        }

        //start부터 end까지의 색인 번호가 있다는 이야기 이므로 정답 배열에 넣어주고 새로운 색인 추가
        answer.push_back(dmap[msg.substr(start_idx, end_idx - start_idx)]);
        dmap.insert({msg.substr(start_idx, end_idx - start_idx +1), ++map_cnt});

        start_idx = end_idx;
    }
    
    return answer;
}