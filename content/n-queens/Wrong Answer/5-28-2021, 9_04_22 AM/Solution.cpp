// https://leetcode.com/problems/n-queens

class Solution {
public:
    vector<string> v;
    vector<vector<bool>> vis;
    vector<vector<string>> ans;
    vector<string> rv;
    vector<vector<bool>> rvis;
    int check;
    void fill(int y,int x,int xs,int ys){
        for(;y<v.size() && x>=0 && x<v[0].size();y+=ys,x+=xs){
            vis[y][x]=true;
        }
    }
    void clear(int y,int x,int xs,int ys){
        for(;y<v.size() && x>=0 && x<v[0].size();y+=ys,x+=xs){
            vis[y][x]=false;
        }
    }
    void put(int x,int level){
        if(vis[level][x]==true){
            return;
        }
        v[level][x]='Q';
        if(level==v.size()-1){
            ans.emplace_back(v);
            return;
        }
        fill(level,x,-1,1);
        fill(level,x,0,1);
        fill(level,x,1,1);
        for(int i=0;i<v[0].size();i++){
            put(i,level+1);
        }
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
            vis[i].assign(n,false);
        }
        rv.assign(v.begin(),v.end());
        rvis.assign(vis.begin(),vis.end());
        for(int i=0;i<n;i++){
            v.assign(rv.begin(),rv.end());
            vis.assign(rvis.begin(),rvis.end());
            put(i,0);
        }
        return ans;
    }
};