// https://leetcode.com/problems/longest-common-subsequence

class Solution {
public:
    int lcs(string& s1,string& s2,int x,int y,vector<vector<int>>& dp){
        if(x<0 || y<0) return 0;
        if(dp[x][y]!=-1) return dp[x][y];
        if(s1[x]==s2[y]){
            dp[x][y]=1+lcs(s1,s2,x-1,y-1,dp);
        }
        else{
            dp[x][y]=max(lcs(s1,s2,x-1,y,dp),lcs(s1,s2,x,y-1,dp));
        }
        return dp[x][y];
    }
    int longestCommonSubsequence(string t1, string t2) {
        int m=t1.size();
        int n=t2.size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        lcs(t1,t2,m-1,n-1,dp);
        return dp[m-1][n-1];
    }
};