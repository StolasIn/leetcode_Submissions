// https://leetcode.com/problems/shortest-path-in-binary-matrix

struct node{
    int x,y,d;  
};
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1) return -1;
        queue<node> q;
        int m=grid.size();
        int n=grid[0].size();
        int x,y,d,ans=-1;
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        q.push(node{0,0,0});
        while(!q.empty()){
            auto t=q.front();
            x=t.x; y=t.y; d=t.d;
            q.pop();
            if(x==m-1 && y==n-1){
                ans=d;
                break;
            }
            if(x<0 || x>=m || y<0 || y>=n) continue;
            if(grid[x][y]==1) continue;
            if(vis[x][y]) continue;
            vis[x][y]=true;
            q.push(node{x-1,y-1,d+1});
            q.push(node{x-1,y,d+1});
            q.push(node{x,y-1,d+1});
            q.push(node{x+1,y,d+1});
            q.push(node{x,y+1,d+1});
            q.push(node{x+1,y+1,d+1});
            q.push(node{x-1,y+1,d+1});
            q.push(node{x+1,y-1,d+1});
        }
        return ans+1;
    }
};