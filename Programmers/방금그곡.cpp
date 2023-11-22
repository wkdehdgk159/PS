//방금그곡 (Level 2, 문자열)
//https://school.programmers.co.kr/learn/courses/30/lessons/17683
#include <string>
#include <vector>
#include <regex>

using namespace std;

string change(string s) {
    s = regex_replace(s, regex("C#"), "c");
    s = regex_replace(s, regex("D#"), "d");
    s = regex_replace(s, regex("F#"), "f");
    s = regex_replace(s, regex("G#"), "g");
    s = regex_replace(s, regex("A#"), "a");
    return s;
}

string solution(string m, vector<string> musicinfos) {
    
    vector<string> musics;
    string answer = "(None)";
    int answer_time_len = 0;
    m = change(m);
    for(int i = 0; i < musicinfos.size(); i++) {
        string musicinfo = musicinfos[i];
        musicinfo = change(musicinfo);
        string title_melody = musicinfo.substr(12);
        string title, melody, total_melody;
        int time_len = 0;
        int h1, h2, m1, m2;
        h1 = stoi(musicinfo.substr(0,2));
        m1 = stoi(musicinfo.substr(3,5));
        h2 = stoi(musicinfo.substr(6,8));
        m2 = stoi(musicinfo.substr(9,11));
        time_len = 60 * (h2-h1) + m2 - m1;
        title = title_melody.substr(0, title_melody.find(","));
        melody = title_melody.substr(title_melody.find(",") + 1);

        for(int j = 0; j <= time_len; j += melody.length()) {
            //남은 시간의 길이가 melody보다 짧다면 substring해서 더해주기
            if(j + melody.length() > time_len) {
                total_melody += melody.substr(0, time_len - j);
                break;
            }
            total_melody += melody;
        }

        if(total_melody.find(m) != -1 && time_len > answer_time_len) {
            answer = title;
            answer_time_len = time_len;
        }
    }
    
    return answer;
}
/*
1. 재생시간동안 틀어지는 멜로디 구하고
2. 그 멜로디.find(m) 으로 포함되어 있는지 확인
3. #을 합쳐 고려해야하니 find 전에 한 문자로 치환해준다.
*/