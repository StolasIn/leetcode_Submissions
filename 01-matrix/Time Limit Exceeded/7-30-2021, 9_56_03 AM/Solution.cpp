// https://leetcode.com/problems/01-matrix

struct node{
    int x,y;  
};
class Solution {
public:
    vector<vector<int>> dp;
    vector<vector<bool>> vis;
    vector<node> dir={node{1,0},node{0,1},node{-1,0},node{0,-1}};
    int m,n;
    int dfs(vector<vector<int>>& mat,int x,int y){
        if(x<0 || x>=m || y<0 || y>=n) return 1e9;
        if(mat[x][y]==0) return 0;
        //if(dp[x][y]!=-1) return dp[x][y];
        if(vis[x][y]==true) return 1e9;
        vis[x][y]=true;
        int mi=1e9;
        for(auto i : dir){
            mi=min(mi,dfs(mat,x+i.x,y+i.y)+1);
        }
        vis[x][y]=false;
        return dp[x][y]=mi;
    }    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        m=mat.size();
        n=mat[0].size();
        dp=vector<vector<int>>(m,vector<int>(n,-1));
        vis=vector<vector<bool>>(m,vector<bool>(n,false));
        vector<vector<int>> ans(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1) ans[i][j]=dfs(mat,i,j);
            }
        }
        //cout<<dfs(mat,9,1)<<endl;
        return ans;
    }
};