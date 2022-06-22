// https://leetcode.com/problems/3sum-closest

class Solution {
    public int threeSumClosest(int[] nums, int target) {
        int mi=Integer.MAX_VALUE;
        int ans=0;
        int l,r;
        Arrays.sort(nums);
        for(int i=0;i<nums.length;i++){
            if(i!=0 && nums[i-1]==nums[i]) continue;
            l=i+1;
            r=nums.length-1;
            while(r>l){
                if(nums[i]+nums[l]+nums[r]==target){
                    return target;
                }
                else if(nums[i]+nums[l]+nums[r]>target){
                    if(mi>Math.abs(target-nums[i]-nums[l]-nums[r])){
                        mi=Math.abs(target-nums[i]-nums[l]-nums[r]);
                        ans=nums[i]+nums[l]+nums[r];
                    }
                    r--;
                }
                else{
                    if(mi>Math.abs(target-nums[i]-nums[l]-nums[r])){
                        mi=Math.abs(target-nums[i]-nums[l]-nums[r]);
                        ans=nums[i]+nums[l]+nums[r];
                    }
                    l++;
                }
            }
        }
        return ans;
    }
}