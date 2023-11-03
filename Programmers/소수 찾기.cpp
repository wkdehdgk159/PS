//소수 찾기(Level 2, 완전탐색)
//https://school.programmers.co.kr/learn/courses/30/lessons/42839?language=cpp

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

int ans = 0;
int cnt[10] = {0};
bool filt[10000000];

//체에서 선택한 수가 어떤 숫자로 구성되어 있는지 count하고 종이 조각으로 충분히 만들 수 있다면 ans++
void check(string num) {
    int tmp_cnt[10] = {0};
    for(int i = 0; i < num.length(); i++) {
        tmp_cnt[num[i] - '0']++; 
    }

    for(int i = 0; i < 10; i++) {
        if(tmp_cnt[i] > cnt[i]) return;
    }
    ans++;
}

int solution(string numbers) {
    
    //숫자 몇개 있는 지 세기
    int len = numbers.length();
    for(int i = 0; i < len; i++) {
        cnt[numbers[i] - '0']++;
    }

    //체 만들기
    memset(filt, true, sizeof(filt));
    int border = 1;
    for(int i = 0; i < len; i++) border *= 10; //이 경계까지 체를 만들어야 함.
    filt[0] = false, filt[1] = false;
    for(int i = 2; i < border; i++) {
        if(filt[i] == 0) continue; //이미 소수가 아닌 것으로 판명 났으면 skip
        for(int j = 2 * i; j < border; j += i) {
            filt[j] = false;
        }
    }

    //체 돌면서 종이 조각으로 구성이 가능한 소수인지 확인
    for(int i = 2; i < border; i++) {
        if(filt[i] == 0) continue;
        check(to_string(i));
    }

    //OUTPUT
    return ans;
}

//1. 종이 조각들 count하여 cnt 배열에 반영
//2. 조각 수를 고려하여 에라토스테네스의 체 만들기
//3. 체에 남겨진 소수들을 돌면서 종이 조각으로 만들 수 있는지 확인
//시간복잡도는... n을 종이조각수로 하면 돌면서 확인하는데 10^n. 체 만드는데 10^n * logn? =? 10^nlogn