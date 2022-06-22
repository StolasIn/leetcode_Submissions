// https://leetcode.com/problems/maximum-length-of-repeated-subarray

class Solution {
public:
    int findLength(vector<int>& n1, vector<int>& n2) {
        int m=n1.size();
        int n=n2.size();
        int dp[m+1][n+1];
        int ma=-1;
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(n1[i-1]==n2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
                ma=max(ma,dp[i][j]);
            }
        }
        return ma;
    }
};