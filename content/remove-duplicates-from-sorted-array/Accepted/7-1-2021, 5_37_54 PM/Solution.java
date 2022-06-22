// https://leetcode.com/problems/remove-duplicates-from-sorted-array

class Solution {
    public int removeDuplicates(int[] nums) {
        HashSet<Integer> s=new HashSet<Integer>();
        int cnt=0;
        for(int i=0;i<nums.length;i++){
            if(s.contains(nums[i])==false){
                s.add(nums[i]);
                nums[cnt++]=nums[i];
            }
        }
        return cnt;
    }
}