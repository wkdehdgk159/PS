//디펜스 게임 (Level 2, 우선순위 큐)
//https://school.programmers.co.kr/learn/courses/30/lessons/142085

#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

int solution(int n, int k, vector<int> enemy) {
     //INPUT
    int answer = 0;
    long long acc_enemy = 0;
    long long acc_mujeok = 0;

    priority_queue<int> pq;

    //SOLVE

    //모든 라운드에 무적권을 쓸 수 있다면?
    if(k >= enemy.size()) return enemy.size();

    for(int i = 0; i < enemy.size(); i++) {
        pq.push(enemy[i]);

        acc_enemy += enemy[i];
        //무적권 사용 없이 못 깨는 판이라면 무적권 사용 후에도 불가능한지 판별
        if(acc_enemy > n) {
            if(k == 0) {
                answer = i;
                break;
            }

            //무적권을 가장 큰 애들부터 쓸만큼만 사용
            while(!pq.empty() && acc_enemy > n) {
                k--;
                acc_enemy -= pq.top();
                pq.pop();
                if(k == 0) {
                    //다 사용해도 못 깨면 전판까지 깼다는 의미
                    if(acc_enemy > n) {
                        answer =  i;
                        break;
                    }
                    //다 사용했을 때 딱 깨면 이번판까지는 클리어
                    else if(acc_enemy == n) {
                        answer =  i + 1;
                        break;
                    }
                    //다 사용했을 때 병사의 여유가 남아있으면 continue;
                }
            }
        }
    }
    
    //모든 라운드를 다 깼다면
    if(acc_enemy <= n) answer = enemy.size();
    
    return answer;
}

/*
1. 하나씩 진행하면서 가장 적의 수가 많은 k개의 표본을 벡터에 담고 정렬해준다. -> 시간 초과 뜸. piority_queue로 정렬 최적화
2. 만약 현재까지 누적 적 수  -  k개의 무적권으로 생략가능한 적의 수가 n보다 커지는 경우 return
*/