// https://leetcode.com/problems/01-matrix

struct node{
    int x;
    int y;
    int s;
};
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<bool>> vis;
    vector<vector<int>> dir = {{-1,0},{0,-1},{1,0},{0,1}};
    void bfs(vector<vector<int>>& mat,int x,int y){
        queue<node> q;
        q.push(node{x,y,0});
        while(!q.empty()){
            auto t = q.front();
            q.pop();
            if(t.x<0 || t.y<0 || t.x>=mat.size() || t.y>=mat[0].size()){
                continue;
            }
            if(vis[t.x][t.y]==true && mat[t.x][t.y]==0){
                continue;
            }
            vis[t.x][t.y]=true;
            if(mat[t.x][t.y]==0){
                t.s = 0;
            }
            //cout<<t.x<<' '<<t.y<<' '<<t.s<<endl;
            if(ans[t.x][t.y]>t.s){
                ans[t.x][t.y] = t.s;
                for(int i=0;i<dir.size();i++){
                    q.push(node{t.x+dir[i][0],t.y+dir[i][1],t.s+1});
                }
            }
        }
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        ans = vector<vector<int>>(m,vector<int>(n,1e9));
        vis = vector<vector<bool>>(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    bfs(mat,i,j);
                    return ans;
                }
            }
        }
        return ans;
    }
};