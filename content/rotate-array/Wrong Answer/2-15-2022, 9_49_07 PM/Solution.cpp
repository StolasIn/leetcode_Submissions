// https://leetcode.com/problems/rotate-array

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k%=nums.size();
        vector<int> ans;
        int m = nums.size();
        for(int i=m-k;i<=m+k;i++){
            ans.emplace_back(nums[(i)%m]);
        }
        nums = ans;
    }
};