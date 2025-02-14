import java.util.*;

class Solution {
    public int[] solution(int brown, int yellow) {
        List<Integer> answer = new ArrayList<>();
        
        int w = 0, h = 0;
        int total = brown + yellow;
        
        for(int i = 1; i <= total; i++) {
            if(total % i != 0) continue;
            
            if((i - 2) * (total / i - 2) == yellow) {
                w = total / i; 
                h = i;
                break;
            }
        }
        
        answer.add(w);
        answer.add(h);
        
        return answer.stream().mapToInt(i -> i).toArray();
    }
}