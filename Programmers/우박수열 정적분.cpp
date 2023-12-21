//우박수열 정적분 (Level 2, 누적합?)
//https://school.programmers.co.kr/learn/courses/30/lessons/134239
#include <string>
#include <vector>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    
    vector<int> height;
    vector<double> acc_sum;

    //SOLVE
    int tmp_k = k;
    int n = 0;
    while(k >= 1) {
        height.push_back(k);

        if(k == 1) break;

        if(k % 2 == 1) {
            k = k * 3 + 1;
        }
        else {
            k /= 2;
        }
        n++;
    }

    k = tmp_k;

    acc_sum.push_back(0);
    for(int i = 1; i < height.size(); i++) {
        double area = (double) (height[i-1] + height[i]) / 2;
        double acc_area = acc_sum[i-1] + area;
        acc_sum.push_back(acc_area);
    }
    
    for(int i = 0; i < ranges.size(); i++) {
        int a = ranges[i][0];
        int b = n + ranges[i][1];

        if(a > b) answer.push_back(-1.0);
        else answer.push_back(acc_sum[b] - acc_sum[a]);
    }
    
    return answer;
}
/*
1. 정적분 누적합 구함. 뺴줌
*/