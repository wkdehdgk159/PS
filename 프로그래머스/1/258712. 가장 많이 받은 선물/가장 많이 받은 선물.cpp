#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    //선물 양, 선물 지수, 이번 달 선물 저장하는 map 선언
    map<string, map<string, int>> m;
    map<string, int> gift_score;
    map<string, int> month_gift;
    
    for(int i = 0; i < friends.size(); i++) {
        for(int j = 0; j < friends.size(); j++) {
            if(i == j) continue;
            m[friends[i]][friends[j]] = 0;
        }
        gift_score[friends[i]] = 0;
        month_gift[friends[i]] = 0;
    }
    
    for(int i = 0; i < gifts.size(); i++) {
        size_t pos = gifts[i].find(' ');
        string A = gifts[i].substr(0, pos);
        string B = gifts[i].substr(pos + 1);
        m[A][B]++;
        gift_score[A]++;
        gift_score[B]--;
    }
    
    //map 순회하면서 선물 카운트
    for(int i = 0; i < friends.size(); i++) {
        const map<string, int>& tmp = m[friends[i]]; // 복사하지 않고 const 참조로 접근
        for(auto it = tmp.begin(); it != tmp.end(); ++it) {
            string a = friends[i];
            string b = it->first;
            
            if(m[a][b] > m[b][a]) {
                month_gift[a]++;
            }
            else if(m[b][a] > m[a][b]) {
                month_gift[b]++;
            }
            else {
                if(gift_score[a] > gift_score[b]) month_gift[a]++;
                else if(gift_score[a] < gift_score[b]) month_gift[b]++;
            }

            // 중복을 제거하기 위해 요소 삭제
            m[b].erase(a);
            
            answer = max(answer, max(month_gift[a], month_gift[b]));
        }
    }
    
    
    return answer;
}