// https://leetcode.com/problems/partition-equal-subset-sum

class Solution {
public:
    bool findSum(vector<int> &nums, int n, int S, vector<vector<int>> &dp){
        if(S == 0)
            return true;
        if(n <= 0 || S < 0)
            return false;
        if(dp[n][S] == -1)
            dp[n][S] = findSum(nums, n-1, S-nums[n-1], dp) || findSum(nums, n-1, S, dp);
        return (dp[n][S]==1)?true:false;
    }
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for_each(nums.begin(), nums.end(), [&](int a){
		    total += a;
	    });
        if(total % 2 != 0)
            return false;
        vector<vector<int>> dp(nums.size()+1, vector<int>(total/2+1,-1));
        return findSum(nums, nums.size(), total/2, dp);
    }
};