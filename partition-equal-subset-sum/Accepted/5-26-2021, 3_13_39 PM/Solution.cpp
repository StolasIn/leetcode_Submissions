// https://leetcode.com/problems/partition-equal-subset-sum

class Solution {
public:
   int dp[20001];
    bool findTheAnswer(vector<int>& nums,int i,int targetSum){
        
        if(targetSum==0)
            return true;
        
        if(i==nums.size() || targetSum<0)
            return false;
        
        if(dp[targetSum]!=-1)
            return dp[targetSum];
        
        return dp[targetSum]=findTheAnswer(nums,i+1,targetSum-nums[i]) || findTheAnswer(nums,i+1,targetSum);
    }
    
    bool canPartition(vector<int>& nums) {
        int sum=0;
        memset(dp,-1,sizeof(dp));
        for(auto i : nums)
            sum+=i;
        if(sum%2==0){
            return findTheAnswer(nums,0,sum/2);
        }
        return false;
    }
};