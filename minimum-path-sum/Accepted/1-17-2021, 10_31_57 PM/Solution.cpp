// https://leetcode.com/problems/minimum-path-sum

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> path(m,vector<int>(n,0));
        path[0][0]=grid[0][0];
        for(int x=0;x<m;x++){
            for(int y=0;y<n;y++){
                if(x>0 && y>0)
                    path[x][y]=min(path[x-1][y],path[x][y-1])+grid[x][y];
                else if(x==0 && y>0)
                    path[x][y]=path[x][y-1]+grid[x][y];
                else if(x>0 && y==0)
                    path[x][y]=path[x-1][y]+grid[x][y];
            }
        }
        return path[m-1][n-1];
    }
};