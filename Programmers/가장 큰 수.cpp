//가장 큰 수 (Level 2, 정렬)
//https://school.programmers.co.kr/learn/courses/30/lessons/42746

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> numbers_to_string;

bool compare(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string ans = "";
    
    for(int i = 0; i < numbers.size(); i++) {
        numbers_to_string.push_back(to_string(numbers[i]));
    }
    
    sort(numbers_to_string.begin(), numbers_to_string.end(), compare);

    for(int i = 0; i < numbers_to_string.size(); i++) {
        ans += numbers_to_string[i];
    }
    
    if(ans[0] == '0') ans = "0";
    
    return ans;
}

//원소가 1000이하이므로 string들을 2번 복사하여 앞 3자리만 비교하는 방법도 있음