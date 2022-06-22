// https://leetcode.com/problems/two-sum

class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] v=new int[2];
        Arrays.sort(nums);
        int l=0,r=nums.length-1;
        while(r>l){
            if(nums[l]+nums[r]==target){
                v[0]=l;
                v[1]=r;
                return v;
            }
            else if(nums[l]+nums[r]>target){
                r--;
            }
            else{
                l++;
            }
        }
        return v;
    }
}