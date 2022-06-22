// https://leetcode.com/problems/random-pick-index

class Solution {
public:
    unordered_map<int,vector<int>> map;
    Solution(vector<int>& nums) {
        int m=nums.size();
        for(int i=0;i<m;i++) map[nums[i]].emplace_back(i);
    }
    
    int pick(int target) {
        return map[target][rand() % map[target].size()];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */