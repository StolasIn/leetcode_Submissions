// https://leetcode.com/problems/build-array-from-permutation

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int m = nums.size();
        vector<int> ans(m);
        for(int i=0;i<m;i++){
            ans[i] = nums[nums[i]];
        }
        return ans;
    }
};