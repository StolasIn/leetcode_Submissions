// https://leetcode.com/problems/n-queens

class Solution {
public:
    vector<string> v;
    vector<vector<int>> vis;
    vector<vector<string>> ans;
    int check;
    void fill(int y,int x,int xs,int ys){
        for(;y<v.size() && x>=0 && x<v[0].size();y+=ys,x+=xs){
            vis[y][x]++;
        }
    }
    void clear(int y,int x,int xs,int ys){
        for(;y<v.size() && x>=0 && x<v[0].size();y+=ys,x+=xs){
            vis[y][x]--;
        }
    }
    void put(int x,int level){
        if(vis[level][x]>=1){
            return;
        }
        if(level==v.size()-1){
            v[level][x]='Q';
            ans.emplace_back(v);
            v[level][x]='.';
            return;
        }
        v[level][x]='Q';
        fill(level,x,-1,1);
        fill(level,x,0,1);
        fill(level,x,1,1);
        for(int i=0;i<v[0].size();i++){
            put(i,level+1);
        }
        v[level][x]='.';
        clear(level,x,-1,1);
        clear(level,x,0,1);
        clear(level,x,1,1);
    }
    vector<vector<string>> solveNQueens(int n) {
        string str(n,'.');
        v.resize(n);
        vis.resize(n);
        for(int i=0;i<n;i++){
            v[i]=str;
            vis[i].assign(n,0);
        }
        for(int i=0;i<n;i++){
            put(i,0);
        }
        return ans;
    }
};