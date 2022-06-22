// https://leetcode.com/problems/maximum-product-subarray

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1=-9999;
        int min1=9999;
        int ans=-999;
        int sum=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++){
            sum*=nums[i];
            max1=max(max1,sum);
            min1=min(min1,sum);
            max1=max(min1*nums[i],max1);
            min1=min(max1*nums[i],min1);
            if(nums[i]==0) {
                sum=1;
                max1=1;
                min1=1;
                ans=max(ans,max1);
            }
        }
        return ans;
    }
};