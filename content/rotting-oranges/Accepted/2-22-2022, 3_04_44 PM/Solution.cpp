// https://leetcode.com/problems/rotting-oranges

struct node{
    int x;
    int y;
    int s;
};
class Solution {
public:
    int orangesRotting(vector<vector<int>>& g) {
        int m = g.size();
        int n = g[0].size();
        queue<node> q;
        int dir[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};
        int ans = 0;
        int cnt = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(g[i][j]==2){
                    q.push(node{i,j,0});
                    g[i][j] = 1;
                    cnt++;
                }
                else if(g[i][j]==1){
                    cnt++;
                }
            }
        }
        while(!q.empty()){
            auto t = q.front();
            q.pop();
            if(t.x<0 || t.y<0 || t.x>=m || t.y>=n){
                continue;
            }
            if(g[t.x][t.y]!=1){
                continue;
            }
            g[t.x][t.y] = 2;
            cnt--;
            ans = max(ans,t.s);
            for(int i=0;i<4;i++){
                q.push(node{t.x+dir[i][0],t.y+dir[i][1],t.s+1});
            }
        }
        return cnt==0 ? ans : -1;
    }
};