class Solution {
    
    int answer = 100;
    
    public void dfs(String begin, String target, String[] words, String curr, boolean[] visited, int len) {
        
        if(curr.equals(target)) {
            answer = Math.min(answer, len);
            return;
        }
        
        for(int i = 0; i < words.length; i++) {
            if(visited[i]) continue;
            
            //하나만 다른가 비교하는 단계
            int cnt = 0;
            for(int j = 0; j < words[i].length(); j++) {
                if(words[i].charAt(j) != curr.charAt(j)) cnt++;
            }
            if(cnt == 1) {
                visited[i] = true;
                dfs(begin, target, words, words[i], visited, len+1);
                visited[i] = false;
            }
        }
        
        return;
    }
    
    public int solution(String begin, String target, String[] words) {
        
        boolean[] visited = new boolean[words.length];
        
        dfs(begin, target, words, begin, visited, 0);
        
        if(answer == 100) answer = 0;
        
        return answer;
    }
}

//DFS로 모든 단어 돌면서 접근 가능하면 더 깊이. visited 표시 주의
//begin, target, words, visited 백트래킹해주기, len