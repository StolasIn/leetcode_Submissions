// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array

class Solution {
public:
    int findMin(vector<int>& nums) {
        int m = nums.size();
        int cmi = min(nums[0],nums[m-1]);
        int l = 0,r = m-1;
        while(r>=l){
            int mid = (r-l)/2 + l;
            cmi = min(cmi,nums[mid]);
            if(mid+1<m && nums[mid]>nums[mid+1]){
                return nums[mid+1];
            }
            else if(mid-1>=0 && nums[mid-1]<nums[mid]){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return cmi;
    }
};