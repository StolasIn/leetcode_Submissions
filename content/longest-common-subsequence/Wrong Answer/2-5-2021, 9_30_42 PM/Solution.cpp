// https://leetcode.com/problems/longest-common-subsequence

class Solution {
public:
    int lcs(string& s1,string& s2,int x,int y,vector<vector<int>>& dp){
        if(x<0 || y<0) return 0;
        if(s1[x]==s2[y]){
            dp[x][y]=1+lcs(s1,s2,x-1,y-1,dp);
            return dp[x][y];
        }
        else{
            return max(lcs(s1,s2,x-1,y,dp),lcs(s1,s2,x,y-1,dp));
        }
    }
    int longestCommonSubsequence(string t1, string t2) {
        vector<vector<int>> dp(t1.size(),vector<int>(t2.size()));
        lcs(t1,t2,t1.size()-1,t2.size()-1,dp);
        return dp[t1.size()-1][t2.size()-1];
    }
};