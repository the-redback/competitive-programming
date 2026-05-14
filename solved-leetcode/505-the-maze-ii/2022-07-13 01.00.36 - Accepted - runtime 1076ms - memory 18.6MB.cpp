int inf=1000000007;
class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        memset(dp, -1, sizeof(dp));
        R=maze.size();
        C=maze[0].size();
        
        dp[start[0]][start[1]] = 0;
        
        desx = destination[0];
        desy = destination[1];
        
        int res=inf;
        rec(maze, start[0], start[1]);
        
        res=dp[desx][desy];
        
        if(res == inf)
            return -1;
        return res;
        
    }
    
    int desx, desy;
    int dp[102][102];
    // 0 = left
    // 1 = up
    // 2 = right
    // 3 = down
    int R, C;
    int dx[4] ={0, -1, 0, 1};
    int dy[4] ={-1, 0 ,1, 0};
    
    void rec(vector<vector<int>>& maze, int r, int c){
        if(r == desx && c== desy)
            return;
        
        for(int i=0; i<4; i++){
            int xx = r+dx[i];
            int yy = c+dy[i];
            int x=r, y=c;
            int steps=dp[x][y];
            while(xx >= 0 && yy>=0 && xx<R && yy < C && maze[xx][yy] != 1){
                x=xx;
                y=yy;
                xx = x+dx[i];
                yy = y+dy[i];
                steps++;
            }
            
            if(dp[x][y] == -1 || dp[x][y]>steps)
            {
                dp[x][y] = steps;
                rec(maze, x, y);
            }
        }
    }
};
