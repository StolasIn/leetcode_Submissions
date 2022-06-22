// https://leetcode.com/problems/maximum-product-subarray

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pro1=1;
        int pro2=1;
        int max1=1;
        int min1=1;
        int sum=1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum*=nums[i];
            max1=max(max1,max(sum,min1*nums[i]));
            min1=min(min1,min(sum,max1*nums[i]));
        }
        return max1;
    }
};