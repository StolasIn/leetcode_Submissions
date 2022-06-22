// https://leetcode.com/problems/shortest-unsorted-continuous-subarray

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int m=nums.size();
        int l=0,r=0;
        for(int i=1;i<m;i++){
            if(nums[i]<nums[i-1]){
                l=min(l,i-1);
                r=max(r,i);
            }
        }
        if(l==0 && r!=0 && r==m-1) return m;
        return r-l;
    }
};