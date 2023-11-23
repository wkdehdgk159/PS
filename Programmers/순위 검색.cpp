//순위 검색(Level 2, 문자열)
//https://school.programmers.co.kr/learn/courses/30/lessons/72412
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    map<string, vector<int> > info_map;
    vector<int> result;

    for(int i = 0; i < info.size(); i++) {
        string tmp_info = info[i];
        string cjp, bf, js, cp, score;
        stringstream ss(tmp_info);
        
        getline(ss, cjp, ' ');
        getline(ss, bf, ' ');
        getline(ss, js, ' ');
        getline(ss, cp, ' ');
        getline(ss, score, ' ');
        string title[16];
        title[0] = cjp+bf+js+cp;
        title[1] = "-"+bf+js+cp;
        title[2] = cjp+"-"+js+cp;
        title[3] = cjp+bf+"-"+cp;
        title[4] = cjp+bf+js+"-";
        title[5] = "--"+js+cp;
        title[6] = "-"+bf+"-"+cp;
        title[7] = "-"+bf+js+"-";
        title[8] = cjp+"-"+"-"+cp;
        title[9] = cjp+"-"+js+"-";
        title[10] = cjp+bf+"-"+"-";
        title[11] = "---"+cp;
        title[12] = "-"+bf+"-"+"-";
        title[13] = cjp+"-"+"-"+"-";
        title[14] = "--"+js+"-";
        title[15] = "----";

        for(int i = 0; i < 16; i++) {
            info_map[title[i]].push_back(stoi(score));
        }
    }

    //정렬
    for(map<string, vector<int> >::iterator it = info_map.begin(); it != info_map.end(); it++) {
        sort(it->second.begin(), it->second.end());
    }

    for(int i = 0; i < query.size(); i++) {
        string tmp_query = query[i];
        string cjp, bf, js, cp, tmp_score, tmp;
        stringstream ss(tmp_query);
        
        getline(ss, cjp, ' ');
        getline(ss, tmp, ' ');
        getline(ss, bf, ' ');
        getline(ss, tmp, ' ');
        getline(ss, js, ' ');
        getline(ss, tmp, ' ');
        getline(ss, cp, ' ');
        getline(ss, tmp_score, ' ');
        

        string title = cjp+bf+js+cp;
        int score = stoi(tmp_score);

        int msize = info_map[title].size();
        //이분 탐색
        if(msize != 0) {
            int mid;
            int start = 0;
            int end = msize;

            while(end > start) {
                mid = (start + end) / 2;
                if(info_map[title][mid] >= score) end = mid;
                else start = mid + 1;
            }
            
            result.push_back(msize - end);
        }
        else {
            result.push_back(0);
        }
    }
    
    return result;
}

/*
1. 총 4*3*3*3 = 108개 조합이 나올 수 있는데 이 경우를 벡터로 만들어서 info들을 집어 넣는다.
2. sort 하고 이분탐색으로 점수 경계 찾기?
*/