// https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m=s1.size();
        int n=s2.size();
        int dp[m+1][n+1];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+s1[i-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int a=0,b=0;
        for(int i=0;i<m;i++){
            a+=s1[i];
        }
        for(int i=0;i<n;i++){
            b+=s2[i];
        }
        return a+b-2*dp[m][n];
    }
};