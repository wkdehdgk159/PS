//메뉴 리뉴얼 (Level 2, 맵)
//https://school.programmers.co.kr/learn/courses/30/lessons/72411
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

map<string, int> cmap;
map<string, int>::iterator iter;

void combination(string order, string comb, int idx, int depth, int r) {
    if(depth == r) {
        cmap[comb] += 1;
        return;
    }
    else {
        for(int i = idx; i < order.length(); i++) {
            string tmp_comb = comb;
            tmp_comb += order[i];
            combination(order, tmp_comb, i + 1, depth+1, r);
        }
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    //SOLVE

    for(int i = 0; i < orders.size(); i++) {
        for(int j = 0; j < course.size(); j++) {
        sort(orders[i].begin(), orders[i].end());
        combination(orders[i], "", 0, 0, course[j]);
        }
    }

    for(int i = 0; i < course.size(); i++) {
        int maxc = 2;
        vector<string> tmp;
        for(iter = cmap.begin(); iter != cmap.end(); iter++) {
            if(iter->first.size() == course[i]) {
                if(iter->second > maxc) {
                    maxc = iter->second;
                    tmp.clear();
                    tmp.push_back(iter->first);
                }
                else if(iter->second == maxc) {
                    tmp.push_back(iter->first);
                }
            }
        }
        for(int j = 0; j < tmp.size(); j++) {
            answer.push_back(tmp[j]);
        }
    }
    sort(answer.begin(), answer.end());
    
    return answer;
}

/*
1. 원하는 구성메뉴 수(2,3,4)에 해당하는 모든 조합 맵으로 만들기
2. 최대값 갱신해주면서 메뉴 담기
*/