// https://leetcode.com/problems/maximum-subarray

class Solution {
    public int maxSubArray(int[] nums) {
        int m = nums.length;
        if(m==0) return 0;
        else if(m==1) return nums[0];
        else if(m==2){
            return Math.max(nums[0]+nums[1],Math.max(nums[0],nums[1]));
        }
        int[] left=Arrays.copyOfRange(nums, 0, m/2);
        int[] right=Arrays.copyOfRange(nums, m/2+1, m);
        int l=maxSubArray(left),r=maxSubArray(right);
        int mal=nums[m/2],mar=nums[(m/2)+1];
        int sum=0;
        for(int i=m/2;i>=0;i--){
            sum+=nums[i];
            mal=Math.max(mal,sum);
        }
        sum=0;
        for(int i=(m/2)+1;i<m;i++){
            sum+=nums[i];
            mar=Math.max(mar,sum);
        }
        return Math.max(mal+mar,Math.max(l,r));
    }
}