// https://leetcode.com/problems/remove-duplicates-from-sorted-array

class Solution {
    public int removeDuplicates(int[] nums) {
        //HashSet<Integer> s=new HashSet<Integer>();
        int cnt=0;
        int pre=-101;
        for(int i=0;i<nums.length;i++){
            if(pre!=nums[i]){
                pre=nums[i];
                nums[cnt++]=nums[i];
            }
        }
        return cnt;
    }
}