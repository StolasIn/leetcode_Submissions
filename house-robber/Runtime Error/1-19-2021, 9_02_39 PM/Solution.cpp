// https://leetcode.com/problems/house-robber

class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,0);
        int max1=0;
        dp[0]=nums[0];
        dp[1]=nums[1];
        dp[2]=dp[0]+nums[2];
        for(int i=3;i<n;i++){
            dp[i]=max(dp[i-2],dp[i-3])+nums[i];
        }
        for(int i=0;i<n;i++){
            max1=max(dp[i],max1);
        }
        return max1;
    }
};