// https://leetcode.com/problems/squares-of-a-sorted-array

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        int l=0,r=nums.size()-1;
        while(r>=l){
            if(nums[l] * nums[l] > nums[r] * nums[r]){
                ans.emplace_back(nums[l] * nums[l]);
                l++;
            }
            else{
                ans.emplace_back(nums[r] * nums[r]);
                r--;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};