import java.util.*;

class Solution {
    public int solution(int[][] rectangle, int characterX, int characterY, int itemX, int itemY) {
        int answer = 0;
        
        //ㄷ자 경로같은 케이스를 위해 좌표를 두배 해주기
        int[][] board = new int[101][101];
        
        //사각형 전체를 1로 채워주기
        for(int[] coor : rectangle) {
            int x1 = coor[0] * 2;
            int y1 = coor[1] * 2; 
            int x2 = coor[2] * 2;
            int y2 = coor[3] * 2;
            
            for(int i = x1; i <= x2; i++) {
                for(int j = y1; j <= y2; j++) {
                    board[i][j] = 1;
                }
            }
        }
        
        //사각형 내부였을 애들은 다시 0으로 채워주기
        for(int[] coor : rectangle) {
            int x1 = coor[0] * 2;
            int y1 = coor[1] * 2; 
            int x2 = coor[2] * 2;
            int y2 = coor[3] * 2;
            
            for(int i = x1 + 1; i < x2; i++) {
                for(int j = y1 + 1; j < y2; j++) {
                    board[i][j] = 0;
                }
            }
        }
        
        answer = bfs(characterX*2, characterY*2, itemX*2, itemY*2, board) / 2;
        
        return answer;
    }
    
    private static final int[] dx = {-1, 1, 0, 0};
    private static final int[] dy = {0, 0, -1, 1};
    
    public int bfs(int cX, int cY, int iX, int iY, int[][] board) {
        
        boolean[][] visited = new boolean[101][101];
        
        Queue<int[]> q = new LinkedList<>();
        
        q.add(new int[] {cX, cY, 0});
        visited[cX][cY] = true;
        
        while(!q.isEmpty()) {
            
            int cx = q.peek()[0];
            int cy = q.peek()[1];
            int cdist = q.peek()[2];
            q.remove();
            
            if(cx == iX && cy == iY) return cdist;
            
            for(int i = 0; i < 4; i++) {
                int nx = cx + dx[i];
                int ny = cy + dy[i];
                
                if(nx < 0 || ny < 0 || nx > 100 || ny > 100 || visited[nx][ny] || board[nx][ny] == 0) continue;
                
                visited[nx][ny] = true;
                q.add(new int[] {nx, ny, cdist+1});
            }
        }
        
        return 0;
    }
}

//그냥 1인 애들 따라가면 끝나는 문제인데. 1의 경계를 어떻게 잘 설정하느냐...
//테두리 1하고 속은 2로 하는데 이미 칸이 2라면 거기는 경계선에서 제외 
//아니면 그냥 경계선 다 1해놓고 속 애들은 0으로 만들어주기. 
//근데 저 디귿자에서 디귿모양으로 가야하는데 바로 위로 올라가는 이슈 발생
//좌표를 2배해주고 거리/2를 해준다.