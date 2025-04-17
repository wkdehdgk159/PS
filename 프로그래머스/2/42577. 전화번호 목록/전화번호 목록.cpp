#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    unordered_map<string, int> map;
    
    for(string s : phone_book) {
        map[s] = 1;
    }
    
    for(string s : phone_book) {
        for(int i = 0; i < s.size() - 1; i++) {
            string phone_number = s.substr(0, i+1);
            if(map[phone_number]) return false;
        }
    }
    
    return answer;
}