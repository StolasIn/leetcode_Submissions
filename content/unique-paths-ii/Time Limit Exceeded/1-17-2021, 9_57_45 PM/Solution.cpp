// https://leetcode.com/problems/unique-paths-ii

class Solution {
public:
    int ans=0;
    void dfs(vector<vector<int>>& obstacleGrid,int x,int y){
        if(x>=obstacleGrid.size() || y>=obstacleGrid[0].size()) return;
        if(obstacleGrid[x][y]==1) return;
        if(x==obstacleGrid.size()-1 && y==obstacleGrid[0].size()-1) ans++;
        dfs(obstacleGrid,x+1,y);
        dfs(obstacleGrid,x,y+1); 
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        dfs(obstacleGrid,0,0);
        return ans;
    }
};