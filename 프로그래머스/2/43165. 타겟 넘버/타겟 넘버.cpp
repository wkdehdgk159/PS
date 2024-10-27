#include <string>
#include <vector>

using namespace std;

int answer = 0;

//depth = 0이 첫번째 숫자, op = 0이 '+'' 
void dfs(int depth, int op, int result, const vector<int>& numbers, const int& target) {
    
    if(op == 0) {
        result += numbers[depth];
    } else {
        result -= numbers[depth];
    }
    
    if(depth == numbers.size()-1) {
        if(result == target) answer++;
        return;
    }
    
    dfs(depth + 1, 0, result, numbers, target);
    dfs(depth + 1, 1, result, numbers, target);
}
    
    
int solution(vector<int> numbers, int target) {
    
    dfs(0, 0, 0, numbers, target);
    dfs(0, 1, 0, numbers, target);
        
    return answer;
}