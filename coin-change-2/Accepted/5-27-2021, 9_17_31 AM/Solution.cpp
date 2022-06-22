// https://leetcode.com/problems/coin-change-2

class Solution {
public:
    int dp[310][5050];
    int change(int amount, vector<int>& coins) {
        int m=coins.size();
        for(int i=0;i<m;i++){
            for(int j=0;j<=amount;j++){
                dp[i][j]=0;
            }
        }
        for(int i=0;i<m;i++) dp[i][0]=1;
        for(int i=1;i<=m;i++){
            for(int j=0;j<=amount;j++){
                if(j>=coins[i-1]){
                    dp[i][j]=dp[i-1][j]+dp[i][j-coins[i-1]];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[m][amount];
    }
};