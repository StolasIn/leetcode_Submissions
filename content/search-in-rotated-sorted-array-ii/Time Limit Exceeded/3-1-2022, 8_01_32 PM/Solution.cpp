// https://leetcode.com/problems/search-in-rotated-sorted-array-ii

class Solution {
public:
    bool search(vector<int>& nums, int t) {
        int m = nums.size();
        int l = 0,r = m-1;
        nums.insert(nums.end(),nums.begin(),nums.end());
        while(r>=l){
            int mid = (r-l)/2 + l;
            if(nums[mid]==t){
                return true;
            }
            else if(nums[mid]<t){
                l = m+1;
            }
            else{
                r = m-1;
            }
        }
        return false;
    }
};