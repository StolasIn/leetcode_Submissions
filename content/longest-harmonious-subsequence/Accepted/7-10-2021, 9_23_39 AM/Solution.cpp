// https://leetcode.com/problems/longest-harmonious-subsequence

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> map;
        int m=nums.size();
        int ma=0;
        for(int i=0;i<m;i++){
            map[nums[i]]++;
        }
        for(int i=0;i<m;i++){
            if(map.find(nums[i]+1)!=map.end()){
                ma=max(ma,map[nums[i]]+map[nums[i]+1]);
            }
            if(map.find(nums[i]-1)!=map.end()){
                ma=max(ma,map[nums[i]]+map[nums[i]-1]);
            }
        }
        return ma;
    }
};