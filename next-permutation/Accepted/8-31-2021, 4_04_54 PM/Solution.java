// https://leetcode.com/problems/next-permutation

class Solution {
    public void nextPermutation(int[] nums) {
        int r=nums.length-2;
        int mi=Integer.MAX_VALUE,pos=0;
        int tmp;
        for(;r>=0;r--){
            if(nums[r+1]>nums[r]){
                break;
            }
        }
        if(r==-1){
            for(int i=0;i<nums.length/2;i++){
                tmp = nums[i];
                nums[i]=nums[nums.length-i-1];
                nums[nums.length-i-1]=tmp;
            }
            return;
        }
        for(int i=nums.length-1;i>r;i--){
            if(nums[i]>nums[r]){
                pos=i;
                break;
            }
        }
        tmp = nums[r];
        nums[r]=nums[pos];
        nums[pos]=tmp;
        Arrays.sort(nums,r+1,nums.length);
    }
}