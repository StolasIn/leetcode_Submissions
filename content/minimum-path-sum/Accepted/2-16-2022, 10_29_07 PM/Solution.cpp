// https://leetcode.com/problems/minimum-path-sum

class Solution {
public:
    int minPathSum(vector<vector<int>>& g) {
        int m = g.size();
        int n = g[0].size();
        int dp[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    dp[i][j] = g[i][j];
                }
                else if(i==0){
                    dp[i][j] = dp[i][j-1] + g[i][j];
                }
                else if(j==0){
                    dp[i][j] = dp[i-1][j] + g[i][j];
                }
                else{
                    dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + g[i][j];
                }
            }
        }
        return dp[m-1][n-1];
    }
};