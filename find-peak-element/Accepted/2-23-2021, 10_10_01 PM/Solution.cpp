// https://leetcode.com/problems/find-peak-element

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1 || nums.size()==0) return 0;
        int l=0;
        int r=nums.size()-1;
        int mid;
        while(r>l){
            mid=(r+l)/2;
            if(nums[mid]>nums[mid+1]){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};