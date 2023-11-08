//모음 사전 (Level 2, 완전탐색, 중복순열)
//https://school.programmers.co.kr/learn/courses/30/lessons/84512

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> vec = {"A", "E", "I", "O", "U"};
void make_permutation_with_repetition(int s_index, int e_index) {
    for(int i = s_index; i <= e_index; i++) {
        for(int j = 0; j < 5; j++) {
            vec.push_back(vec[i] + vec[j]);
        }
    } 
    if(vec[vec.size() - 1].length() == 5) return;
    else {
        make_permutation_with_repetition(e_index + 1, vec.size() - 1);
    }
}


int solution(string word) {
    int ans = 0;
    
    //중복순열 모든 경우 구하기
    make_permutation_with_repetition(0, 4);
    //사전순으로 정렬
    sort(vec.begin(), vec.end());
    
    for(int i = 0; i < vec.size(); i++) {
        if(vec[i] == word) {
            ans = i + 1;
            break;
        }
    }
    
    return ans;
}