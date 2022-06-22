// https://leetcode.com/problems/longest-increasing-subsequence

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ca;
        int m=nums.size();
        ca.emplace_back(nums[0]);
        for(int i=1;i<m;i++){
            if(nums[i]>ca[ca.size()-1]){
                ca.emplace_back(nums[i]);
            }
            else{
                auto iter = lower_bound(ca.begin(),ca.end(),nums[i]);
                (*iter)=nums[i];
            }
        }
        return ca.size();
    }
};