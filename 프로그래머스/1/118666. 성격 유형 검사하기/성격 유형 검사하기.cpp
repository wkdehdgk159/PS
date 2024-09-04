#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    
    string answer = "RCJA";
    
    map<char, int> m;
    
    for(int i = 0; i < survey.size(); i++) {
        if(choices[i] > 4) m[survey[i][1]] -= 4 - choices[i];
        else m[survey[i][0]] += 4 - choices[i];
    }
    
    if(m['T'] > m['R']) answer[0] = 'T';
    if(m['F'] > m['C']) answer[1] = 'F';
    if(m['M'] > m['J']) answer[2] = 'M';
    if(m['N'] > m['A']) answer[3] = 'N';
    
    
    return answer;
}