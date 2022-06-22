// https://leetcode.com/problems/maximum-subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int max1=-999999;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            max1=max(sum,max1);
            if(sum<0) sum=0;
        }
        return max1;
    }
};