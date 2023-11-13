//광물 캐기 (Level 2, 완전탐색, 중복순열)
//https://school.programmers.co.kr/learn/courses/30/lessons/172927

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int ans = 999999;
vector<int> picked_picks;

int solution(vector<int> picks, vector<string> minerals) {
    //광물을 다 캐려면 곡괭이가 몇개 필요한가.
    int needed_pick = minerals.size() / 5 + 1;
    
    //더 좋은 곡괭이부터 골라 넣기.
    while(needed_pick-- > 0) {
        if(picks[0] > 0) {
            picked_picks.push_back(1);
            picks[0]--;
            continue;
        }
        if(picks[1] > 0) {
            picked_picks.push_back(2);
            picks[1]--;
            continue;
        }
        if(picks[2] > 0) {
            picked_picks.push_back(3);
            picks[2]--;
            continue;
        }
    }

    //
    do {
        int tmp = 0;
        for(int i = 0; i < picked_picks.size(); i++) {
            int cpick = picked_picks[i]; //현재 곡괭이
            
            //현재 곡괭이로 광물 5개 채집
            for(int j = i * 5; j < (i+1) * 5; j++) {
                if(j == minerals.size()) break;
                //다이아 곡괭이면 뭐든지 +1
                if(cpick == 1) tmp += 1;
                //철 곡괭이
                else if(cpick == 2) {
                    if(minerals[j] == "diamond") tmp += 5;
                    else tmp += 1;
                }
                //돌 곡괭이
                else if(cpick == 3) {
                    if(minerals[j] == "diamond") tmp += 25;
                    else if(minerals[j] == "iron") tmp += 5;
                    else tmp += 1;
                }

            }
        }
        
        ans = (ans < tmp) ? ans : tmp;
    }while(next_permutation(picked_picks.begin(), picked_picks.end())); //다음 조합으로 try

    if(ans == 999999) return 0;
    return ans;
}
/*
1. 좋은 곡괭이부터 차례대로 곡괭이 후보군에 집어 넣는다.
2. 곡괭이 후보군의 모든 순열조합을 확인하면서 최소값 찾기

** DFS 완탐도 가능 
*/