// https://leetcode.com/problems/two-sum

class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] v=new int[2];
        Arrays.sort(nums);
        HashMap<Integer,Integer> map=new HashMap<Integer,Integer>();
        for(int i=0;i<nums.length;i++){
            map.put(nums[i],i);
        }
        int l=0,r=nums.length-1;
        while(r>l){
            if(nums[l]+nums[r]==target){
                v[0]=map.get(nums[l]);
                v[1]=map.get(nums[r]);
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