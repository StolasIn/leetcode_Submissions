// https://leetcode.com/problems/unique-paths-ii

class Solution {
public:
    int ans=0;
    int m,n;
    /*void dfs(vector<vector<int>>& obstacleGrid,int x,int y){
        if(x>=m || y>=n) return;
        if(obstacleGrid[x][y]==1) return;
        if(x==m-1 && y==n-1) ans++;
        dfs(obstacleGrid,x+1,y);
        dfs(obstacleGrid,x,y+1); 
    }*/
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m=obstacleGrid.size();
        n=obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1) return 0;
        vector<vector<int>> path(m,vector<int>(n,0));
        path[0][0]=1;
        for(int x=0;x<m;x++){
            for(int y=0;y<n;y++){
                if(obstacleGrid[x][y]==1) continue;
                if(x>0 && y>0)
                    path[x][y]=path[x-1][y]+path[x][y-1];
                else if(x==0 && y>0)
                    path[x][y]=path[x][y-1];
                else if(x>0 && y==0)
                    path[x][y]=path[x-1][y];
            }
        }
        //dfs(obstacleGrid,0,0,path);
        return path[m-1][n-1];
    }
};