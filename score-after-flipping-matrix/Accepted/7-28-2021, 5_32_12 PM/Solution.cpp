// https://leetcode.com/problems/score-after-flipping-matrix

class Solution {
public:
    void flip(vector<int>& g){
        for(int i=0;i<g.size();i++){
            g[i]=!g[i];
        }
    }
    void check(vector<vector<int>>& g,int col){
        int cnt=0;
        for(int i=0;i<g.size();i++){
            if(g[i][col]==0) cnt++;
        }
        if(cnt>g.size()/2){
            for(int i=0;i<g.size();i++){
                g[i][col]=!g[i][col];
            }
        }
    }
    int bin(vector<int>& v){
        int ans=0;
        int m=v.size();
        for(int i=0;i<m;i++){
            if(v[i]==1) ans+=(1<<(m-i-1));
        }
        return ans;
    }
    int matrixScore(vector<vector<int>>& g) {
        int m=g.size();
        int n=g[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            if(g[i][0]==0){
                flip(g[i]);
            }
        }
        for(int i=1;i<n;i++){
            check(g,i);
        }
        for(int i=0;i<m;i++){
            ans+=bin(g[i]);
        }   
        return ans;
    }
};