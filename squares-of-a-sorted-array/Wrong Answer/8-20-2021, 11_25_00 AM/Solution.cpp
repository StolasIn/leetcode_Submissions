// https://leetcode.com/problems/squares-of-a-sorted-array

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int m = nums.size();
        vector<int> ans(m);
        int l=0,r=m-1;
        int cnt=m-1;
        while(r>l){
            if(nums[l]*nums[l]>nums[r]*nums[r]){
                ans[cnt--]=nums[l]*nums[l];
                l++;
            }
            else{
                ans[cnt--]=nums[r]*nums[r];
                r--;
            }
        }
        return ans;
    }
};