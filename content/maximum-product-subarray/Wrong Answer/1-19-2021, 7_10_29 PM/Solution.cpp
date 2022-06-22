// https://leetcode.com/problems/maximum-product-subarray

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1=-9999;
        int min1=9999;
        int sum=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++){
            max1=max(max1,sum);
            min1=min(min1,sum);
            sum*=nums[i];
            max1=max(min1*nums[i],max1);
            min1=min(max1*nums[i],min1);
            if(nums[i]==0) sum=1;
        }
        return max1;
    }
};