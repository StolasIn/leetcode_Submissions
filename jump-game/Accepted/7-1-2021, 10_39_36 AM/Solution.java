// https://leetcode.com/problems/jump-game

class Solution {
    public boolean canJump(int[] nums) {
        int m=nums.length;
        int l=m-1;
        for(int i=m-1;i>=0;i--){
            if(i+nums[i]>=l){
                l=i;
            }
        }
        return l==0;
    }
}