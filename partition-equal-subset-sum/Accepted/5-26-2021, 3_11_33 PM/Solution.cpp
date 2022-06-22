// https://leetcode.com/problems/partition-equal-subset-sum

class Solution {
public:
    bool canPartition(vector<int>& n) {
        int sum = 0;
        int m = n.size();
        for(int i=0;i<m;i++){
            sum+=n[i];
        }
        if(sum%2!=0){
            return false;
        }
        else{
            sum/=2;
        }
        int dp[m+1][sum+1];
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int i=1;i<m;i++){
            for(int j=0;j<=sum;j++){
                if(j>=n[i]){
                    dp[i][j] = max(dp[i-1][j],dp[i-1][j-n[i]]);
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        if(dp[m-1][sum]>0) return true;
        return false;
    }
};