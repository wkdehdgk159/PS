#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

bool compare_genre(pair<string, int> a, pair<string, int> b) {
    return a.second > b.second;
}

bool compare_song(pii a, pii b) {
    if(a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    map<string, int> m; //재생횟수
    map<string, vector<pii>> m2; //(고유번호, 재생횟수)
    
    for(int i = 0; i < genres.size(); i++) {
        m[genres[i]] += plays[i];
        m2[genres[i]].push_back({i, plays[i]});
    }
    
    //맵을 벡터로 복사. value로 정렬하기 위해
    vector<pair<string, int>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), compare_genre);
    
    for(pair<const string, vector<pii>>& a: m2) {
        sort(a.second.begin(), a.second.end(), compare_song);
    }
    
    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < m2[v[i].first].size(); j++) {
            if(j == 2) break;
            answer.push_back(m2[v[i].first][j].first);
        }
    }
    
    return answer;
}

//장르 우선 -> 재생 횟수 우선 -> 고유번호 오름차순
//<장르, 재생횟수>로 맵 만들고 장르 순위
//장르별로 벡터<(고유번호, 재생 횟수)> 만들어서 기준에 맞게 정렬