//피로도 (Level 2, 완전탐색)
//https://school.programmers.co.kr/learn/courses/30/lessons/87946

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int ans = -1;
    //next_permutation이 끝까지 돌기 위해서 오름차순 sort
    sort(dungeons.begin(), dungeons.end());

    //가능한 모든 순열을 돌기
    do {
        int tmp_k = k, tmp_cnt = 0;
        for(int i = 0; i < dungeons.size(); i++) {
            //현재 피로도가 충분하지 않다면 컷
            if(dungeons[i][0] > tmp_k) continue;
            //필요 피로도가 충분하다면 소모 피로도 깎아주고 cnt++
            else {
                tmp_k -= dungeons[i][1];
                tmp_cnt++;
            }
        }
        ans = (tmp_cnt > ans) ? tmp_cnt : ans;
    }while(next_permutation(dungeons.begin(), dungeons.end()));
    
    //next_permutation이 어떤 원리인가 하니 현재 순열보다 내림차순이 되는 기준으로 다음 순열을 찾는다.
    //예를 들어 {4,3,2,1} 이면 이것보다 더 내림차순스러운 순열이 없기에 false 반환.
    
    return ans;
}