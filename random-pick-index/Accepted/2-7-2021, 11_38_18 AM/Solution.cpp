// https://leetcode.com/problems/random-pick-index

class Solution {
public:
    unordered_map<int,vector<int>> map;
    Solution(vector<int>& nums) {
        int m=nums.size();
        for(int i=0;i<m;i++) map[nums[i]].emplace_back(i);
    }
    
    int pick(int target) {
        int n=map[target].size();
        return map[target][rand()%n];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */