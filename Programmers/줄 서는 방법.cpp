//줄 서는 방법 (Level 2, 수학)
//https://school.programmers.co.kr/learn/courses/30/lessons/12936
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

#define ll long long
using namespace std;

int arr[21];
bool check[21];

ll facto(ll n) {
    if(n == 1 || n == 0) return 1;
    else {
        return facto(n-1) * n;
    }
}

vector<int> solution(int n, long long k) {
    vector<int> answer;
    
    //INPUT
    for(int i = 1; i <= n; i++) {
        arr[i] = i;
    }
    memset(check, 0, sizeof(check));
    
    //SOLVE
    for(int i = 1; i <= n; i++) {
        int cnt = 0;
        ll div = facto(n - i);

        //남은 숫자들 중에 몇번째를 노려야 하는지
        //나머지가 0인 경우를 고려하여 -1
        ll target = (k-1) / div;
        k = k % div;
        if(k == 0) k = div;

        for(int j = 1; j <= n; j++) {
            //이미 채택된 숫자라면 skip
            if(check[j]) continue;

            if(cnt == target) {
                answer.push_back(j);
                check[j] = true;
                break;
            }
            cnt++;
        }
    }
    
    return answer;
}