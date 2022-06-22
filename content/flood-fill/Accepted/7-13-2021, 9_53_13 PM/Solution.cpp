// https://leetcode.com/problems/flood-fill

struct node{
    int x,y;  
};
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& im, int sr, int sc, int newColor) {
        queue<node> q;
        int col=im[sr][sc];
        if(col==newColor) return im;
        q.push(node{sr,sc});
        int x,y;
        while(!q.empty()){
            x=q.front().x;
            y=q.front().y;
            q.pop();
            if(x<0 || x>=im.size() || y<0 || y>=im[0].size()) continue;
            if(im[x][y]!=col) continue;
            im[x][y]=newColor;
            q.push(node{x-1,y});
            q.push(node{x,y-1});
            q.push(node{x+1,y});
            q.push(node{x,y+1});
        }
        return im;
    }
};