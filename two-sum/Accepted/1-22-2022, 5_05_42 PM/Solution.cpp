// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int t) {
        unordered_map<int,int> map;
        int m=nums.size();
        for(int i=0;i<m;i++){
            if(map.find(t-nums[i])!=map.end()){
                return {map[t-nums[i]],i};
            }
            map[nums[i]]=i;
        }
        return {-1,-1};
    }
};