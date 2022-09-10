//https://school.programmers.co.kr/learn/courses/30/lessons/118667
//두 큐 합 같게 만들기

#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    long long sum1 = accumulate(queue1.begin(), queue1.end(), 0LL);
    long long sum2 = accumulate(queue2.begin(), queue2.end(), 0LL);
    if((sum1 + sum2) % 2 == 1) return -1;
    int len = queue1.size();
    
    queue1.insert(queue1.end(), queue2.begin(), queue2.end());
    
    int cnt = 0;
    int ans = 0;
    int p1_1 = 0, p1_2 = len - 1, p2_1 = len, p2_2 = 2 * len - 1;
    
    while(cnt <= 4 * len) {
        int tmp;
        if(sum1 == sum2) return ans;
        else if(sum1 > sum2) {
            tmp = queue1[p1_1];
            sum1 -= tmp;
            sum2 += tmp;
            
            if(p1_1 + 1 >= len * 2) p1_1 = 0;
            else p1_1++;
            if(p2_2 + 1 >= len * 2) p2_2 = 0;
            else p2_2++;
            ans++;
        } else if(sum1 < sum2) {
            tmp = queue1[p2_1];
            sum2 -= tmp;
            sum1 += tmp;
            
            if(p2_1 + 1 >= len * 2) p2_1 = 0;
            else p2_1++;
            if(p1_2 + 1 >= len * 2) p1_2 = 0;
            else p1_2++;
            ans++;
        }
        cnt++;
    }
    return -1;
}

//큐를 써서 풀어도 되지만 투 포인터로 해결