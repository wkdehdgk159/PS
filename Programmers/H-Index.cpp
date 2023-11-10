//H-Index (Level 2, 정렬)
//https://school.programmers.co.kr/learn/courses/30/lessons/42747

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int ans = 0;
    
    sort(citations.begin(), citations.end());
    int len = citations.size();
    
    for(int i = 0; i < len; i++) {
        //H-Index가 될 수 있는 후보군은 1~citations.length() 이다.
        //정렬된 배열의 인덱스를 돌면서 남은 논문들은 다 현재 citations 이상의 인용횟수를 가지고 있을테니
        //현재 인덱스의 인용횟수가 남은 논문 개수 이상이 되는 순간 H-Index가 확정
        if(len - i <= citations[i]) {
            ans = len - i;
            break;
        }
    }
    
    return ans;
}