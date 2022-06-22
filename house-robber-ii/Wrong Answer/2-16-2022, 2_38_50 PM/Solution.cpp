// https://leetcode.com/problems/house-robber-ii

class Solution {
public:
    unordered_map<int,int>  dp;
    int re(vector<int>& nums,int n,int l){
        if(n<0) return 0;
        if(dp.find(n)!=dp.end()){
            return dp[n];
        }
        if(n==1){
            return nums[n];
        }
        if(n==0){
            if(l!=0 && l==nums.size()-1){
                return 0;
            } 
            else{
                return nums[n];
            }
        }
        return dp[n] = max(re(nums,n-3,l),re(nums,n-2,l)) + nums[n];
    }
    int rob(vector<int>& nums) {
        return max(re(nums,nums.size()-1,nums.size()-1),re(nums,nums.size()-2,nums.size()-2));
    }
};