// https://leetcode.com/problems/move-zeroes

class Solution {
    public void moveZeroes(int[] nums) {
        int l=0;
        while(l<nums.length && nums[l]!=0){
            l++;
        }
        if(l==nums.length) return;
        int tmp;
        for(int i=l;i<nums.length;i++){
            if(nums[i]!=0){
                tmp = nums[l];
                nums[l]=nums[i];
                nums[i]=tmp;
            }
            while(nums[l]!=0 && l<nums.length){
                l++;
            }
        }
    }
}