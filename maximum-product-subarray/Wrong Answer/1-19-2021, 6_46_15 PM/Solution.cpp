// https://leetcode.com/problems/maximum-product-subarray

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1=1;
        int min1=1;
        int sum=-9999;
        int n=nums.size();
        for(int i=0;i<n;i++){
            max1=max(min1*nums[i],max1*nums[i]);
            max1=max(nums[i],max1);
            min1=min(min1*nums[i],max1*nums[i]);
            min1=min(nums[i],min1);
            sum=max(max1,sum);
        }
        return sum;
    }
};