// https://leetcode.com/problems/number-of-closed-islands

class Solution {
public:
    bool flag;
    vector<vector<bool>> vis;
    void dfs(vector<vector<int>>& g,int x,int y){
        if(x<0 || x>=g.size() || y<0 || y>=g[0].size()){
            flag=true;
            return;
        }
        if(vis[x][y]==true || g[x][y]==1){
            return;
        }
        vis[x][y]=true;
        dfs(g,x-1,y);
        dfs(g,x,y-1);
        dfs(g,x+1,y);
        dfs(g,x,y+1);
    }
    int closedIsland(vector<vector<int>>& g) {
        vis=vector<vector<bool>>(g.size(),vector<bool>(g[0].size(),false));
        int ans=0;
        for(int i=0;i<g.size();i++){
            for(int j=0;j<g[0].size();j++){
                if(g[i][j]==0 && vis[i][j]==false){
                    flag=false;
                    dfs(g,i,j);
                    if(flag==false){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};