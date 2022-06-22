// https://leetcode.com/problems/move-zeroes

class Solution {
    public void moveZeroes(int[] nums) {
        int cnt=0;
        for(int i=0;i<nums.length;i++){
            if(nums[i]!=0){
                nums[cnt++]=nums[i];
            }
        }
        for(int i=cnt;i<nums.length;i++){
            nums[i]=0;
        }
    }
}