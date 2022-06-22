// https://leetcode.com/problems/3sum

class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> ans= new ArrayList<List<Integer>>();
        int l,r;
        for(int i=0;i<nums.length;i++){
            if(i!=0 && nums[i-1]==nums[i]) continue;
            l=i+1;
            r=nums.length-1;
            while(r>l){
                if(nums[i]+nums[l]+nums[r]==0){
                    List<Integer> tmp=new ArrayList<Integer>();
                    tmp.add(nums[i]);
                    tmp.add(nums[l]);
                    tmp.add(nums[r]);
                    ans.add(tmp);
                    while(l<r && nums[r]==nums[r-1]) r--;
                    while(l<r && nums[l]==nums[l+1]) l++;
                    l++;
                    r--;
                }
                else if(nums[i]+nums[l]+nums[r]>0){
                    r--;
                }
                else{
                    l++;
                }
            }
        }
        return ans;
    }
}