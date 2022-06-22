// https://leetcode.com/problems/triangle

class Solution {
public:
    int re(vector<vector<int>>& tr,vector<vector<int>>& dp,vector<vector<bool>>& vis,int l,int x){
        if(l>=tr.size() || l<0 || x>=tr[l].size() || x<0) return INT_MAX;
        if(l==0) return tr[0][0];
        if(vis[l][x]==true) return dp[l][x];
        vis[l][x]=true;
        dp[l][x]+=min(re(tr,dp,vis,l-1,x),re(tr,dp,vis,l-1,x-1));
        return dp[l][x];
    }
    int minimumTotal(vector<vector<int>>& tr) {
        int m=tr.size();
        int mi=INT_MAX;
        vector<vector<int>> dp(tr.begin(),tr.end());
        vector<vector<bool>> vis(m,vector<bool>(m,false));
        for(int i=0;i<m;i++)
            re(tr,dp,vis,m-1,i);
        for(int i=0;i<dp[m-1].size();i++){
            mi=min(mi,dp[m-1][i]);
        }
        return mi;
    }
};