// https://leetcode.com/problems/house-robber

class Solution {
public:
    unordered_map<int,int>  dp;
    int re(vector<int>& nums,int n){
        if(n<0) return 0;
        if(dp.find(n)!=dp.end()){
            return dp[n];
        }
        if(n==0 || n==1){
            return nums[n];
        }
        return dp[n] = max(re(nums,n-3),re(nums,n-2)) + nums[n];
    }
    int rob(vector<int>& nums) {
        return max(re(nums,nums.size()-1),re(nums,nums.size()-2));
    }
};