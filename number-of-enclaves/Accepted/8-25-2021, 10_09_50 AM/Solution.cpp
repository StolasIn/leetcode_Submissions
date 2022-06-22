// https://leetcode.com/problems/number-of-enclaves

class Solution {
public:
    bool flag;
    int cnt;
    vector<vector<bool>> vis;
    void dfs(vector<vector<int>>& g,int x,int y){
        if(x<0 || x>=g.size() || y<0 || y>=g[0].size()){
            flag=true;
            return;
        }
        if(g[x][y]==0 || vis[x][y]==true) return;
        vis[x][y]=true;
        cnt++;
        dfs(g,x-1,y);
        dfs(g,x,y-1);
        dfs(g,x+1,y);
        dfs(g,x,y+1);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int m = grid.size();
        int n = grid[0].size();
        vis=vector<vector<bool>> (m,vector<bool>(n,false));
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==false && grid[i][j]==1){
                    flag=false;
                    cnt=0;
                    dfs(grid,i,j);
                    if(flag==false){
                        ans+=cnt;
                    }
                }
            }
        }
        return ans;
    }
};