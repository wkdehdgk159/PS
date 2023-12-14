//튜플 (Level 2, 정렬)
//https://school.programmers.co.kr/learn/courses/30/lessons/64065
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

bool cmp(vector<int> a, vector<int> b) {
    if (a.size() < b.size()) return true;
    else return false;
}
bool visited[100001];

vector<int> solution(string s) {
    vector<int> answer;

    vector<vector<int> > sv;

    int s_idx = 1;

    while(s_idx < s.length()) {

        //집합의 시작(맨 처음 제외)
        if(s[s_idx] == '{') {
            vector<int> tmp;
            //집합이 닫히기 전까지
            s_idx++;
            while(s[s_idx] != '}') {
                int r = 0;

                // 현재 수가 끝나기 전까지
                while(s[s_idx] != ',' && s[s_idx] != '}' ) {
                    r = r * 10 + s[s_idx] - '0';
                    s_idx++;
                }

                tmp.push_back(r);

                if(s[s_idx] == '}') break;
                //다음 수로
                r = 0;
                s_idx++;
            }

            //다음 집합으로(다음 '{' 으로) 
            s_idx += 2;
            sv.push_back(tmp);
        }
    }

    //SOLVE
    //집합의 크기가 큰 순으로 정렬
    sort(sv.begin(), sv.end(), cmp);
    
    memset(visited, false, sizeof(visited));
    visited[sv[0][0]] = true;
    answer.push_back(sv[0][0]);
    
    for(int i = 1; i < sv.size(); i++) {
        for(int j = 0; j < sv[i].size(); j++) {
            if(!visited[sv[i][j]]) {
                answer.push_back(sv[i][j]);
                visited[sv[i][j]] = true;
                break;
            }
        }
    }

    return answer;
}

/*
1. 데이터 잘 가공한 다음 길이 순으로 정렬
2. 짧은 집합에 있는 원소부터 넣어주고 visited로 체크해주면서 새로운 원소 넣기
*/