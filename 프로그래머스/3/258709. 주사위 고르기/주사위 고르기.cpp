#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<int>> diceArr; //dice 복사할 벡터
vector<int> diceA, diceB; //주사위 idx 담는 벡터
vector<int> arrA, arrB; //나오는 합을 담는 벡터
int max_total_win = 0, n;

void cal_arr(int idx, int sum, bool isA) {
    if(idx == n / 2) {
        if(isA) arrA.push_back(sum);
        else arrB.push_back(sum);
        return;
    }
    
    for(int i = 0; i < 6; i++) {
        int diceIdx = 0;
        if(isA) diceIdx = diceA[idx];
        else diceIdx = diceB[idx];
        
        cal_arr(idx + 1, sum + diceArr[diceIdx][i], isA);
    }
}

vector<int> solution(vector<vector<int>> dice) {
    n = dice.size();
    diceArr = dice;
    vector<int> answer(n / 2);
    
    //주사위 조합용 (0,1) 벡터
    vector<int> tmp(n, 1);
    
    //앞 2/n 개 0으로 세팅
    for(int i = 0; i < n/2; i++) {
        tmp[i] = 0;
    }
    
    do {
        //벡터들 초기화
        diceA.clear();
        diceB.clear();
        arrA.clear();
        arrB.clear();
        
        //주사위 조합 완성
        for(int i = 0; i < n; i++) {
            if(tmp[i] == 0) diceA.push_back(i);
            else diceB.push_back(i);
        }
        
        //주사위 조합으로 나올 수 있는 경우의 수 구하기
        cal_arr(0,0,1);
        cal_arr(0,0,0);
        
        //나오는 합들 정렬
        sort(arrA.begin(), arrA.end());
        sort(arrB.begin(), arrB.end());
        
        //원소들 비교해가며 승리 횟수 구하기
        //포인터 하나씩 두면서 arrA의 원소가 더 크다면 arrB 포인터 늘려주고
        //arrB 원소가 더 큰 시점이 온다면 그때까지의 arrB idx 더해주고 arrA 포인터 늘려준다.
        //비기는 경우는? -> 이기는 경우만 셀 것이기 때문에 arrB가 더 크다고 처리해준다.
        int idxA = 0, idxB = 0;
        int total_win = 0;
        while(idxA < arrA.size() && idxB < arrB.size()) {
            if(arrA[idxA] > arrB[idxB]) idxB++;
            else {
                total_win += idxB;
                idxA++;
            }
        }
        //B가 먼저 끝나면 B 전체 경우의 수를 이기는 A 경우의 수가 존재한다는 뜻이다.
        if(idxB == arrB.size()) {
            total_win += idxB * (arrA.size() - idxA);
        }
        
        //승리 횟수가 최대인지 판별하고 최대라면 정답 벡터 갱신
        if(total_win > max_total_win) {
            max_total_win = total_win;
            for(int i = 0; i < diceA.size(); i++) {
                answer[i] = diceA[i] + 1;
            }
        }
        
    }while(next_permutation(tmp.begin(), tmp.end()));
        
    return answer;
}


//주사위 조합의 수는 최대 10C5 - next_permutation과 (0,1) 벡터로 조합 만들어주기
//dfs로 나올 수 있는 주사위의 합 구하기 6^5 * 2
//각각 정렬한 후에 앞에서부터 비교하면서 이기는 경우의 수 구하기 (정렬 mlogm + m, m = 6^5)
//Big-O 는 O(mlogm)