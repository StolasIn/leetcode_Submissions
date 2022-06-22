// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array

class Solution {
public:
    int findMin(vector<int>& nums) {
        int cmi = nums[0];
        int m = nums.size();
        int l = 0,r = m-1;
        while(r>=l){
            int mid = (r-l)/2 + l;
            if(mid+1<m && nums[mid]>nums[mid+1]){
                return nums[mid+1];
            }
            else{
                l = mid+1;
            }
        }
        return cmi;
    }
};