// https://leetcode.com/problems/unique-paths-ii

class Solution {
public:
    int ans=0;
    int m,n;
    void dfs(vector<vector<int>>& obstacleGrid,int x,int y){
        if(x>=m || y>=n) return;
        if(obstacleGrid[x][y]==1) return;
        if(x==m-1 && y==n-1) ans++;
        dfs(obstacleGrid,x+1,y);
        dfs(obstacleGrid,x,y+1); 
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m=obstacleGrid.size();
        n=obstacleGrid[0].size();
        dfs(obstacleGrid,0,0);
        return ans;
    }
};