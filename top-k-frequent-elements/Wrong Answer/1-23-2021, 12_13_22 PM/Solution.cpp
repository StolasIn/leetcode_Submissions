// https://leetcode.com/problems/top-k-frequent-elements

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        vector<int> ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            map[nums[i]]++;
        }
        for(auto i : map){
            if(i.second>=k) ans.push_back(i.first);
        }
        return ans;
    }
};