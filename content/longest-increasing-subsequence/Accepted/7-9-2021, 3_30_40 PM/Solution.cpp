// https://leetcode.com/problems/longest-increasing-subsequence

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> v;
        for(int i=0;i<nums.size();i++){
            if(v.empty() || v.back()<nums[i]){
                v.emplace_back(nums[i]);
            }
            else{
                *lower_bound(v.begin(),v.end(),nums[i])=nums[i];
            }
        }
        return v.size();
    }
};