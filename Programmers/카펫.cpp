//카펫(Level 2, 완전탐색)
https://school.programmers.co.kr/learn/courses/30/lessons/42842

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    //INPUT
    vector<int> answer;
    int size = brown + yellow;
    int width, height;
    
    //SOLVE
    for(int i = 3; i <= 1667; i++) {
        if(size % i != 0) continue;
        height = i, width = size / i;
        if((width - 2) * (height - 2) == yellow) break;
    }

    //OUTPUT
    answer.push_back(width);
    answer.push_back(height);
    
    return answer;
}

/*
1. brown + yellow는 합성수 일 수 밖에 없다.
2. 모든 조합(w, h)을 돌면서 w-2 * h-2 가 yellow가 나오는 경우를 찾는다.
** brown이 5000이하이기 때문에 width의 최대값은 대략 5000/3
*/