// https://leetcode.com/problems/maximum-product-subarray

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1=-9999;
        int min1=1;
        int sum=1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            max1=max(max1,max(sum*nums[i],nums[i]));
            min1=min(min1,min(sum*nums[i],nums[i]));
            sum*=nums[i];
            if(nums[i]==0) sum=1;
        }
        return max1;
    }
};