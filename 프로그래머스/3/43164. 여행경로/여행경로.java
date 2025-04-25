import java.util.*;

class Solution {
    List<String> answer = null;
    boolean[] visited;

    public String[] solution(String[][] tickets) {
        visited = new boolean[tickets.length];

        // 사전순 탐색을 위해 먼저 정렬
        Arrays.sort(tickets, (a, b) -> a[0].equals(b[0]) 
                                       ? a[1].compareTo(b[1]) 
                                       : a[0].compareTo(b[0]));

        List<String> path = new ArrayList<>();
        path.add("ICN");
        dfs("ICN", tickets, path, 0);

        return answer.toArray(new String[0]);
    }

    private void dfs(String curr, String[][] tickets, List<String> path, int used) {
        if (used == tickets.length) {
            answer = new ArrayList<>(path); // 깊은 복사
            return;
        }

        for (int i = 0; i < tickets.length; i++) {
            if (!visited[i] && tickets[i][0].equals(curr)) {
                visited[i] = true;
                path.add(tickets[i][1]);

                dfs(tickets[i][1], tickets, path, used + 1);
                if (answer != null) return; // 이미 정답 찾았으면 중단 (사전순 보장 위해)

                visited[i] = false;
                path.remove(path.size() - 1); // 백트래킹
            }
        }
    }
}
