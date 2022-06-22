// https://leetcode.com/problems/maximum-product-difference-between-two-pairs

class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int m = nums.size()-1;
        nth_element(nums.begin(),nums.begin()+3,nums.end());
        nth_element(nums.begin(),nums.begin()+m-3,nums.end());
        return nums[m] * nums[m-1] - nums[0] * nums[1];
    }
};