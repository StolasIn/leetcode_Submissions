// https://leetcode.com/problems/maximum-product-of-three-numbers

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int m=nums.size();
        sort(nums.begin(),nums.end());
        return max(nums[0]*nums[1]*nums[m-1],nums[m-3]*nums[m-2]*nums[m-1]);
    }
};