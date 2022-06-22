// https://leetcode.com/problems/n-queens-ii

class Solution {
public:
    vector<vector<int>> vis;
    int total;
    void fill(int y,int x,int xs,int ys){
        for(;y<vis.size() && x>=0 && x<vis[0].size();y+=ys,x+=xs){
            vis[y][x]++;
        }
    }
    void clear(int y,int x,int xs,int ys){
        for(;y<vis.size() && x>=0 && x<vis[0].size();y+=ys,x+=xs){
            vis[y][x]--;
        }
    }
    void put(int x,int level){
        if(vis[level][x]>=1){
            return;
        }
        if(level==vis.size()-1){
            total++;
            return;
        }
        fill(level,x,-1,1);
        fill(level,x,0,1);
        fill(level,x,1,1);
        for(int i=0;i<vis[0].size();i++){
            put(i,level+1);
        }
        clear(level,x,-1,1);
        clear(level,x,0,1);
        clear(level,x,1,1);
    }
    int totalNQueens(int n) {
        vis.resize(n);
        for(int i=0;i<n;i++){
            vis[i].assign(n,false);
        }
        for(int i=0;i<n;i++){
            put(i,0);
        }
        return total;
    }
};