//전화번호 목록 (Level 2, 해시, 정렬)
//https://school.programmers.co.kr/learn/courses/30/lessons/42577

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    sort(phone_book.begin(), phone_book.end());

    for(int i = 0; i < phone_book.size() - 1; i++) {
        string s1 = phone_book[i];
        string s2 = phone_book[i+1];
        int s1_len = s1.length(), s2_len = s2.length();
        //앞의 길이가 더 길다는 건 종류가 달라졌다는 뜻
        if(s1_len > s2_len) continue;

        //s2 잘라봐서 s1과 같으면 false 반환
        if(s1 == s2.substr(0, s1_len)) return false;
    }
    
    return answer;
}

/*
1. 오름차순으로 정렬. string이기 때문에 앞이 비슷한 놈들끼리 묶일 것
2. 순회하면서 현재 전화번호가 뒷 전화번호의 앞과 똑같은지 체크
*/