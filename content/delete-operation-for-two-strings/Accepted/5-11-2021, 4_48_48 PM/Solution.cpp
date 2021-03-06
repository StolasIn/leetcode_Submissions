// https://leetcode.com/problems/delete-operation-for-two-strings

class Solution {
public:
    int minDistance(string s1, string s2) {
        int m=s1.size();
        int n=s2.size();
        int dp[m+1][n+1];
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                dp[i][j]=0;
            }
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return (m-dp[m][n])+(n-dp[m][n]);
    }
};