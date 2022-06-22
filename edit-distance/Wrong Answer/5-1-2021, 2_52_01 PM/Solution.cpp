// https://leetcode.com/problems/edit-distance

class Solution {
public:
    int minDistance(string w1, string w2) {
        int m=w1.size();
        int n=w2.size();
        if(m==0 && n==0) return 0;
        if(m==0) return n;
        if(n==0) return m;
        int dp[m+1][n+1];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<=n;i++){
            dp[0][i]=i;
        }
        for(int i=0;i<=m;i++){
            dp[i][0]=i;
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(w1[i]==w2[j]){
                    dp[i][j]=min(dp[i-1][j]+1,dp[i][j-1]+1);
                    dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
                }
                else{
                    dp[i][j]=min(dp[i-1][j]+1,dp[i][j-1]+1);
                    dp[i][j]=min(dp[i][j],dp[i-1][j-1]+1);
                }
            }
        }
        return dp[m][n]+1;
    }
};