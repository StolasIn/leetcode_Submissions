// https://leetcode.com/problems/maximum-subarray

class Solution {
    public int maxSubArray(int[] nums) {
        int sum=0;
        int ma=nums[0];
        for(int i=0;i<nums.length;i++){
            sum+=nums[i];
            ma=Math.max(ma,sum);
            if(sum<0){
                sum=0;
            }
        }
        return ma;
    }
}