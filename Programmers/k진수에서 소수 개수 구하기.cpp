//https://school.programmers.co.kr/learn/courses/30/lessons/92335
//k진수에서 소수 개수 구하기 (Level 2, 구현)

#include <string>
#include <vector>
#include <cmath>
#include <list>

using namespace std;

bool is_Prime(long long num) {
    if (num < 2) return false;
    for(int i = 2; i <= sqrt(num); i++) {
        if(num % i == 0) return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    
    list<int> k_jinsoo;
    
    long long num = 0;
    for(int i = n; i > 0; i /= k) {
        k_jinsoo.push_front(i % k);
    }
    k_jinsoo.push_back(0);
    for(list<int>::iterator it = k_jinsoo.begin(); it != k_jinsoo.end(); it++) {
        if(*it == 0) {
            if(is_Prime(num)) answer++;
            num = 0;
        } else {
            num = num * 10 + *it;
        }
    }
    return answer;
}
//자료형 오버플로우만 조심하자!