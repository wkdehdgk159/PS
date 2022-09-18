//https://school.programmers.co.kr/learn/courses/30/lessons/118670
//행렬과 연산 (Level 4, 구현)

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
#include <deque>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> rc, vector<string> operations) {
    vector<vector<int>> answer;
    int r = rc.size();
    int c = rc[0].size();
    answer.assign(r, vector<int>(c, 0));
    
    vector<int> idx; //idx[0]의 의미 현재 0번째 row가 처음 몇번째 row였는지
    idx.assign(r, 0);
    for(int i = 0; i < r; i++) {
        idx[i] = i;
    }
    
    //왼쪽 오른쪽 column을 담당하는 deque선언
    deque<int> left, right;
    for(int i = 0; i < r; i++) {
        left.push_back(rc[i][0]);
        right.push_back(rc[i][c-1]);
    }
    
    vector<deque<int>> mat(r);
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c - 2; j++) {
            mat[i].push_back(rc[i][j+1]);
        }
    }
    
    
    for(int i = 0; i < operations.size(); i++) {
        //Rotate는 해당되는 list들의 앞뒤 원소만 처리해준다.
        if(operations[i].compare("Rotate") == 0) {
            //일단 밀릴 애들 넣어주고
            right.push_front(mat[idx[0]].back());
            mat[idx[r-1]].push_back(right.back());
            left.push_back(mat[idx[r-1]].front());
            mat[idx[0]].push_front(left.front());
            
            //삭제
            mat[idx[0]].pop_back();
            right.pop_back();
            mat[idx[r-1]].pop_front();
            left.pop_front();
        }
        //ShiftRow는 row만 한줄씩 밀려나는 것이기에 이를 idx 벡터에 반영해주고 left,right에서는 맨 아래 원소를 위로 올려준다
        if(operations[i].compare("ShiftRow") == 0) {
            for(int j = 0; j < r; j++) {
                idx[j]--;
                if(idx[j] == -1) idx[j] = r-1;
            }
            left.push_front(left.back());
            left.pop_back();
            right.push_front(right.back());
            right.pop_back();
        }
    }
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(j == 0) {
                answer[i][j] = left.front();
                left.pop_front();
            } 
            else if(j == c - 1) {
                answer[i][j] = right.front();
                right.pop_front();
            }
            else {
                answer[i][j] = mat[idx[i]].front();
                mat[idx[i]].pop_front();
                
            }
        }
    }
    return answer;
}

//효율성 3문제가 deque를 써도 list를 써도 실패가 나온다(5번은 시간초과 4,6번은 seg fault). 그래도 익숙한 list보다 deque를 써봤다는 것에 의의를 두고 다음에 다시 도전해보련다(파이썬이면 그냥 될 것 같은데..)