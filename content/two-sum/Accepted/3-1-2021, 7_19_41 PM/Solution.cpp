// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int t) {
        unordered_map<int,int> map;
        vector<int> ans;
        int m=nums.size();
        int comp;
        for(int i=0;i<m;i++){
            comp=t-nums[i];
            if(map.find(comp)!=map.end()){
                ans.emplace_back(map[comp]);
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