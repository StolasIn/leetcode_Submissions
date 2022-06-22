// https://leetcode.com/problems/minimum-falling-path-sum

class Solution {
public:
    vector<vector<int>> dp;
    int re(vector<vector<int>>& v,int r,int c){
        if(c<0 || c>=v[0].size()) return 1e9;
        if(dp[r][c]!=1e9){
            return dp[r][c];
        }
        if(r==0){
            int mi=1e9;
            for(int i=c-1;i<(c+1);i++){
                if(i>=0 || i<v[0].size()) mi=min(mi,v[0][i]);
            }
            return dp[r][c]=mi;
        }
        else{
            return dp[r][c]=v[r][c]+min(re(v,r-1,c-1),min(re(v,r-1,c),re(v,r-1,c+1)));
        }
    }
    int minFallingPathSum(vector<vector<int>>& mat) {
        dp=vector<vector<int>>(mat.size(),vector<int>(mat[0].size(),1e9));
        int mi=1e9;
        for(int i=0;i<mat[0].size();i++){
            mi=min(mi,re(mat,mat.size()-1,i));
        }
        return mi;
    }
};