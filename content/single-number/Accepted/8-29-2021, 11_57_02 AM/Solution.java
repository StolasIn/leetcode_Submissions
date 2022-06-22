// https://leetcode.com/problems/single-number

class Solution {
    public int singleNumber(int[] nums) {
        int mask=nums[0];
        for(int i=1;i<nums.length;i++){
            mask^=nums[i];
        }
        return mask;
    }
}