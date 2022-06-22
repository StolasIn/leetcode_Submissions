// https://leetcode.com/problems/find-peak-element

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int m=nums.size();
        int l=0,r=m-1,mid;
        if(nums.size()<=1) return 0;
        if(nums[0]>nums[1]){
            return 0;
        }
        if(nums[m-2]<nums[m-1]){
            return m-1;
        }
        while(r>l){
            mid=(r+l)/2;
            if(mid==0 || mid==m-1) return -1;
            if(nums[mid-1]<nums[mid] && nums[mid]>nums[mid+1]){
                return mid;
            }
            else if(nums[mid-1]<nums[mid] && nums[mid]<nums[mid+1]){
                l=mid;
            }
            else if(nums[mid-1]>nums[mid] && nums[mid]>nums[mid+1]){
                r=mid;
            }
            else{
                if(m-mid>m/2){
                    r=mid;
                }
                else{
                    l=mid;
                }
            }
        }
        return -1;
    }
};