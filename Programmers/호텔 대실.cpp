//호텔 대실 (Level 2, 정렬)
//https://school.programmers.co.kr/learn/courses/30/lessons/155651
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int time_to_minute(string s) {
    int hour = stoi(s.substr(0, 2));
    int minute = stoi(s.substr(3, 2));
    return hour * 60 + minute;
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    
    //INPUT
    vector<vector<int> > book_time_to_minute;//String 시간의 총합으로 치환(분 단위)
    vector<int> possible_time;//각 방마다 사용가능한 시간.
    
    //SOLVE

    sort(book_time.begin(), book_time.end());
    for(int i = 0; i < book_time.size(); i++) {
        vector<int> tmp;
        tmp.push_back(time_to_minute(book_time[i][0]));
        tmp.push_back(time_to_minute(book_time[i][1]));
        book_time_to_minute.push_back(tmp);
    }

    for(int i = 0; i < book_time_to_minute.size(); i++) {
        bool gf = false;
        int start_time = book_time_to_minute[i][0];
        for(int j = 0; j < possible_time.size(); j++) {
            //들어갈 공실이 있다면 공실 채워주고 새로운 사용가능시간 갱신
            if(possible_time[j] <= start_time) {
                possible_time[j] = book_time_to_minute[i][1] + 10;
                gf = true;
                break;
            }
        }
        //공실이 없다면 새로운 방 넣어주기(possible_time size가 1 늘어남)
        if(!gf) possible_time.push_back(book_time_to_minute[i][1] + 10);
    }
    
    //OUTPUT
    answer = possible_time.size();
    
    return answer;
}
/*
1. 입실할 때마다 재사용가능한 방이 있는지 체크한다.
2. 방이 존재한다면 해당 방의 재사용 가능한 시간을 갱신해주고
3. 없다면 새로운 방을 사용한다고 가정하여 그 방이 사용가능한 시간을 벡터에 넣어준다.
*/