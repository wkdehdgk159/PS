//최솟값 만들기 (Level 2, 정렬)
//https://school.programmers.co.kr/learn/courses/30/lessons/12941
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;

    sort(A.begin(), A.end());
    sort(B.rbegin(), B.rend());
    
    for(int i = 0; i < A.size(); i++) {
        answer += A[i] * B[i];
    }

    return answer;
}
// 각각 오름차순 정렬, 내림차순 정렬 해줘서. 큰 수끼리 곱해지는 경우를 피하기.