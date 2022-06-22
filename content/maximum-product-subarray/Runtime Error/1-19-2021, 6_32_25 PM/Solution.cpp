// https://leetcode.com/problems/maximum-product-subarray

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pro1=1;
        int pro2=1;
        int max1=-INT_MAX;
        int min1;
        int sum=1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum*=nums[i];
            max1=max(max1,sum);
            max1=max(max1,min1*nums[i]);
            min1=min(min1,sum);
            min1=min(min1,max1*nums[i]);
        }
        return max1;
    }
};