// https://leetcode.com/problems/maximum-product-difference-between-two-pairs

class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int n=nums.size();
        nth_element(nums.begin(), nums.begin()+1, nums.end());
        int firstmin=nums[0],secmin=nums[1];
        nth_element(nums.begin(), nums.begin()+1, nums.end(),greater<int>());
        int firstmax=nums[0],secmax=nums[1];
        return firstmax*secmax - firstmin*secmin;
    }
};