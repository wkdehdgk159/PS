//테이블 해시 함수 (Level 2, 정렬)
//https://school.programmers.co.kr/learn/courses/30/lessons/147354

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int c;
bool cmp(vector<int> a, vector<int> b) {
    if(a[c] == b[c]) {
        return a[0] > b[0];
    }
    return a[c] < b[c];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    vector<vector<int>> d;
    d = data;
    
    c = col-1;
    
    sort(d.begin(), d.end(), cmp);
    
    vector<int> s_i;
    for(int i = row_begin; i <= row_end; i++) {
        int result = 0;
        for(int j = 0; j < d[i-1].size(); j++) {
            result += d[i-1][j] % i;
        }
        s_i.push_back(result);
    }
    
    for(int i = row_begin; i <= row_end; i++) {
        answer = answer ^ s_i[i-row_begin];
    }
    
    return answer;
}