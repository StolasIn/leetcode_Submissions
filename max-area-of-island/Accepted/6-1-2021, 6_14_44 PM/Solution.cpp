// https://leetcode.com/problems/max-area-of-island

class Solution {
public:
    int m,n;
    int ans;
    bool vis[55][55];
    void dfs(vector<vector<int>>& g,int x,int y){
        if(x<0 || y<0 || x>=m || y>=n) return;
        if(g[x][y]==0 || vis[x][y]==true) return;
        vis[x][y]=true;
        ans++;
        dfs(g,x,y+1);
        dfs(g,x+1,y);
        dfs(g,x,y-1);
        dfs(g,x-1,y);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                vis[i][j]=false;
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans=0;
                if(grid[i][j]!=0 && vis[i][j]==false) dfs(grid,i,j);
                res=max(ans,res);
            }
        }
        return res;
    }
};