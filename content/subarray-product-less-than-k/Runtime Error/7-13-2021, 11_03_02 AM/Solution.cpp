// https://leetcode.com/problems/subarray-product-less-than-k

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int m=nums.size();
        int l=0,r=0;
        int sum=1;
        int ans=0;
        while(r<m){
            if(sum<k){
                ans+=r-l+1;
                sum*=nums[r];
                r++;
            }
            else{
                sum/=nums[l];
                l++;
            }
        }
        return ans-1;
    }
};