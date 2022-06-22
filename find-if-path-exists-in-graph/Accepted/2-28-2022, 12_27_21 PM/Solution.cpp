// https://leetcode.com/problems/find-if-path-exists-in-graph

class dist{
public:
    vector<int> par;
    dist(int x){
        par.assign(x,-1);
    }
    int find(int x){
        int x1 = x;
        while(par[x]>=0){
            x = par[x];
        }
        int x2;
        while(par[x1]>=0){
            x2 = par[x1];
            par[x1] = x;
            x1 = x2;
        }
        return x;
    }
    bool union_n(int x,int y){
        int m = find(x);
        int n = find(y);
        if(m!=-1 && m==n){
            return true;
        }
        if(par[m]>par[n]){
            par[n]+=par[m];
            par[m] = n;
        }
        else{
            par[m]+=par[n];
            par[n] = m;
        }
        return false;
    }
};
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& e, int source, int dest) {
        dist d = dist(n);
        for(int i=0;i<e.size();i++){
            d.union_n(e[i][0],e[i][1]);
        }
        return d.union_n(source,dest);
    }
};