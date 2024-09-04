#include <string>
#include <vector>
#include <iostream>

using namespace std;

int arr[600001];

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -1;
    long long sum1 = 0, sum2 = 0;
    
    for(int i = 0; i < queue1.size(); i++) {
        sum1 += queue1[i];
        sum2 += queue2[i];
    }
    
    //합이 홀수면 -1 리턴
    if((sum1 + sum2) % 2 == 1) return -1;
    if(sum1 == sum2) return 0;
    
    //더 합이 큰 배열을 뒤에 붙여준다.
    if(sum1 <= sum2) {
        for(int i = 0; i < queue1.size(); i++) {
            arr[i] = queue1[i];
        }
        for(int i = queue1.size(); i < queue1.size() * 2; i++) {
            arr[i] = queue2[i - queue1.size()];
        }
    }
    else {
        for(int i = 0; i < queue1.size(); i++) {
            arr[i] = queue2[i];
        }
        for(int i = queue1.size(); i < queue1.size() * 2; i++) {
            arr[i] = queue1[i - queue1.size()];
        }
    }
    
    int p1, p2;
    
    if(sum1 <= sum2) {
        p1 = 0, p2 = queue1.size();
    }
    else {
        p2 = 0, p1 = queue1.size();   
    }
    
    while(p1 < queue2.size() * 2 && p2 < queue2.size() * 2) {
        
        if(sum1 == sum2) {
            answer = p1 + p2 - queue1.size();
            break;
        }
        else if(sum1 < sum2) {
            sum1 += arr[p2];
            sum2 -= arr[p2];
            p2++;
        }
        else {
            sum2 += arr[p1];
            sum1 -= arr[p1];
            p1++;
        }
        
    }
    
    return answer;
}

/*
일단 총합 구해서 각 큐가 몇을 가져야 하는지 판단.
투포인터 느낌으로 부족한 큐에서 선택해서 나아가자.
*/