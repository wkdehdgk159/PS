#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long ll;

long long solution(int n, vector<int> times) {
    
    ll answer = 0;
    sort(times.begin(), times.end());
    
    ll start = 0;
    ll end = (ll) n * (ll) times.back();
    
    while(start <= end) {
        ll mid = (start + end) / 2;
        ll cnt = 0;
        
        for(int i = 0; i < times.size(); i++) {
            cnt += mid / times[i];
        }
        
        //심사할 수 있는 사람 수가 더 많으면 시간을 더 줄일 수 있을 것
        if(cnt >= n) {
            end = mid - 1;
            answer = mid;
        }
        
        else start = mid + 1;
        
    }
    
    return answer;
}

//이분탐색 문제인 걸 알고 풀어도 모르겠네
//7분 심사대에 몇명 들어가는지 -> 10분 심사대에 몇명 들어가는지 -> 이런식으로 최적값 찾아가며 DFS?
//2^30 승이니까 첫 심사대 30번 -> 두번째 심사대 15 8 4 2
//아 sort에 vector이름 다르게 넣어서 seg fault 계속뜸
//와 애초에 접근이 틀렸다 멍청한 녀석... 걸리는 시간을 이분탐색하면 되는 걸..
//최대시간을 가장 긴 심사시간 x n으로 잡고 줄여가면서, 그 시간 내에 심사대에서 받을 수 있는 고객의 총 수가 n과 근접하도록