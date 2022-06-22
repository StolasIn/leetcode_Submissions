// https://leetcode.com/problems/maximum-product-subarray

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1=1;
        int min1=1;
        int ans=-999;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int tmp=max1;
            max1=max(min1*nums[i],max(max1*nums[i],nums[i]));
            min1=min(tmp*nums[i],min(min1*nums[i],nums[i]));
            ans=max(max1,ans);
            if(nums[i]==0){
                max1=1;
                min1=1;
            }
        }
        return ans;
    }
};