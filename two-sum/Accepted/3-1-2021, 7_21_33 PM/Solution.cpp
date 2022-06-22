// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int t) {
        unordered_map<int,int> map;
        vector<int> ans;
        int m=nums.size();
        for(int i=0;i<m;i++){
            if(map.find(t-nums[i])!=map.end()){
                ans.emplace_back(map[t-nums[i]]);
                ans.emplace_back(i);
                return ans;
            }
            else{
                map[nums[i]]=i;
            }
        }
        return ans;
    }
};