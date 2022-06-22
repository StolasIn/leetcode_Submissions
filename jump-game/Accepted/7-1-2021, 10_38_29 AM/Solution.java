// https://leetcode.com/problems/jump-game

class Solution {
    public boolean canJump(int[] nums) {
        int i1;
        for(int i=nums.length-1;i>=0;){
        System.out.println(i);
            i1=i;
            for(int j=i-1;j>=0;j--){
                if(nums[j]+j>=i){
                    i=j;
                    break;
                }
            }
            if(i==0) return true;
            if(i1==i){
                return false;
            }
        }
        return true;
    }
}