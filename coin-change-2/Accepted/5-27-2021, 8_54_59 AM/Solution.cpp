// https://leetcode.com/problems/coin-change-2

class Solution {
public:
    int dp[5050];
    int change(int amount, vector<int>& coins) {
        for(int i=0;i<=amount;i++){
            dp[i]=0;
        }
        dp[0]=1;
        for(auto& i : coins){
            for(int j=i;j<=amount;j++){
                dp[j]+=dp[j-i];
            }
        }
        return dp[amount];
    }
};