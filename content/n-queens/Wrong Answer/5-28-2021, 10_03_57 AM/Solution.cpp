// https://leetcode.com/problems/n-queens

class Solution {
public:
    vector<string> v;
    vector<vector<bool>> vis;
    vector<vector<bool>> tmp;
    vector<vector<string>> ans;
    int check;
    void fill(int y,int x,int xs,int ys){
        for(;y<v.size() && x>=0 && x<v[0].size();y+=ys,x+=xs){
            vis[y][x]=true;
        }
    }
    void put(int x,int level){
        if(vis[level][x]==true){
            return;
        }
        if(level==v.size()-1){
            v[level][x]='Q';
            ans.emplace_back(v);
            v[level][x]='.';
            return;
        }
        tmp = vis;
        v[level][x]='Q';
        fill(level,x,-1,1);
        fill(level,x,0,1);
        fill(level,x,1,1);
        for(int i=0;i<v[0].size();i++){
            put(i,level+1);
        }
        vis=tmp;
        v[level][x]='.';
    }
    vector<vector<string>> solveNQueens(int n) {
        string str(n,'.');
        v.resize(n);
        vis.resize(n);
        for(int i=0;i<n;i++){
            v[i]=str;
            vis[i].assign(n,false);
        }
        for(int i=0;i<n;i++){
            put(i,0);
        }
        return ans;
    }
};