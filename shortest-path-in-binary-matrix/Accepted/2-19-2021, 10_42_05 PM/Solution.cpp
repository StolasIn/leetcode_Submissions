// https://leetcode.com/problems/shortest-path-in-binary-matrix

struct node{
    int x,y,d;  
};
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m=grid.size();
        if(grid[0][0]==1 || grid[m-1][m-1]==1) return -1;
        queue<node> q;
        int x,y,d;
        vector<vector<bool>> vis(m,vector<bool>(m,false));
        q.push(node{0,0,0});
        while(!q.empty()){
            auto t=q.front();
            x=t.x; y=t.y; d=t.d;
            q.pop();
            if(x==m-1 && y==m-1){
                return d+1;
            }
            if(x<0 || x>=m || y<0 || y>=m) continue;
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
        return -1;
    }
};